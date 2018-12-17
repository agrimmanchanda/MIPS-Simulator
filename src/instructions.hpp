#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP
/*
The set of functions here are used to execute the instructions in a way that simulates the MIPS ISA instructions
They take the relevant parameters depending on the instruction type (R,I,J) that were extracted earlier and perform the
instruction, returning the relevent mips error code (0 if no error)
*/
#include <stdint.h>
#include <climits>
#include <vector>
#include "memory.cpp"

typedef int32_t reg;

//remove later
typedef int32_t mips_error;

// mips_error data_access (std::vector <uint8_t> &ADDR_DATA, uint32_t address, int32_t &data, bool R, bool word);


//R type (Opcode: 000000)                                             //Function code:
mips_error ADD (const reg &rs,const reg &rt, reg &rd);                //100000
mips_error ADDU (const reg &rs,const reg &rt, reg &rd);               //100001
mips_error AND (const reg &rs,const reg &rt, reg &rd);                //100100
mips_error JR (const reg &rs, int32_t &B_dest);                       //001000
mips_error MFHI (reg &rd, reg &HI);                                   //010000
mips_error MFLO (reg &rd, reg &LO);                                   //010010
mips_error MTHI (reg &rs, reg &HI);                                   //010001
mips_error MTLO (reg &rs, reg &LO);                                   //010011
mips_error OR (const reg &rs,const reg &rt, reg &rd);                 //100101
mips_error SLL (const reg &rt, reg &rd, uint32_t sa);                 //000000
mips_error SLLV (const reg &rs, const reg &rt, reg &rd);              //000100
mips_error SLT (const reg &rs,const reg &rt, reg &rd);                //101010
mips_error SLTU (const reg &rs,const reg &rt, reg &rd);               //101011
mips_error SRA (const reg &rt, reg &rd, uint32_t sa);                 //000011
mips_error SRAV (const reg &rs, const reg &rt, reg &rd);              //000111
mips_error SRL (const reg &rt, const reg &rd, uint32_t sa);           //000010
mips_error SUB (const reg &rs, const reg &rt, reg &rd);               //100010
mips_error SUBU (const reg &rs, const reg &rt, reg &rd);              //100011
mips_error XOR (const reg &rs, const reg &rt, reg &rd);               //100110
mips_error SRLV (const reg &rs, const reg &rt, reg &rd);              //000110
mips_error JALR(const reg &rs, const reg &rt, reg &rd, const int32_t &PC);
mips_error MULT(const reg &rs, const reg &rt, reg &HI, reg &LO);
mips_error MULTU(const reg &rs, const reg &rt, reg &HI, reg &LO);
mips_error DIV(const reg &rs, const reg &rt, reg &HI, reg &LO);
mips_error DIVU(const reg &rs, const reg &rt, reg &HI, reg &LO);


//I type                                                                                                     //Opcode:
mips_error ADDI (const reg &rs, reg &rt, int16_t imm);                                                       //001000
mips_error ADDIU (const reg &rs, reg &rt, int16_t imm);                                                      //001001
mips_error ANDI (const reg &rs, reg &rt, int16_t imm);                                                       //001100
mips_error BEQ (const reg &rs, const reg &rt, const int16_t &imm, const uint32_t &B_del, int32_t &B_dest);   //000100
mips_error BGEZ (const reg &rs, const int16_t &imm, const uint32_t &B_del, int32_t &B_dest);                 //000001 (Special)
mips_error BGEZAL (const reg &rs, const int16_t &imm, const uint32_t &B_del, int32_t &B_dest, const reg &id_1, const reg &r31);               //000001 (Special)
mips_error BGTZ (const reg &rs, const int16_t &imm, const uint32_t &B_del, int32_t &B_dest);                 //000111
mips_error BLEZ (const reg &rs, const int16_t &imm, const uint32_t &B_del, int32_t &B_dest);                 //000110
mips_error BLTZ (const reg &rs, const int16_t &imm, const uint32_t &B_del, int32_t &B_dest);                 //000001 (Special)
mips_error BLTZAL (const reg &rs, const int16_t &imm, const uint32_t &B_del, int32_t &B_dest, const reg &id_1, const reg &r31);               //000001 (Special)
mips_error BNE (const reg &rs, const reg &rt, const int16_t &imm, const uint32_t &B_del, int32_t &B_dest);   //000101
mips_error LB (const reg &base, reg &rt, int16_t offset, Memory &MIPS_Memory);                               //100000
mips_error LBU (const reg &base, reg &rt, int16_t offset, Memory &MIPS_Memory);                              //100100
mips_error LH (const reg &base, reg &rt, int16_t offset, Memory &MIPS_Memory);                               //100001
mips_error LHU (const reg &base, reg &rt, int16_t offset, Memory &MIPS_Memory);                              //100101
mips_error LUI (reg &rt, int16_t imm);                                                                       //001111
mips_error LW (const reg &base, reg &rt, int16_t offset, Memory &MIPS_Memory);                               //100011
mips_error ORI (const reg &rs, reg &rt, int16_t imm);                                                        //001101
mips_error SB (const reg &base, reg &rt, int16_t offset, Memory &MIPS_Memory);                               //101000
mips_error SH (const reg &base, reg &rt, int16_t offset, Memory &MIPS_Memory);                               //101001
mips_error SLTI (const reg &rs, reg &rt, int16_t imm);                                                       //001010
mips_error SLTIU (const reg &rs, reg &rt, int16_t imm);                                                      //001011
mips_error SW (const reg &base, const reg &rt, int16_t offset, Memory &MIPS_Memory);                         //101011
mips_error XORI (const reg &rs, reg &rt, int16_t imm);                                                       //001110


//J type
mips_error J (uint32_t &instr_index, const uint32_t &B_del, int32_t &B_dest);
mips_error JAL (const reg &r31, const uint32_t &B_del, int32_t &B_dest, const int32_t &PC);                               //000010


mips_error ex_instructions (int32_t* mips_registers, uint32_t* instruction_data, Memory &MIPS_Memory, uint32_t B_del, int32_t &B_dest, int32_t &HI,int32_t &LO);
#endif
