#ifndef DECODE_HPP
#define DECODE_HPP
/*
DECODE
This set of functions perform the DECODE operation
They accept the instruction, decode the internals
and separate the bits into individual fields, agreed beforehand
3 functions - 3 types: R, I, J
*/

#include <iostream>
#include <stdint.h>

typedef int32_t mips_error;
using namespace std;

mips_error mips_decode(const uint32_t& instruction, uint32_t* instruction_data);
mips_error mips_decode_R(const uint32_t& instruction, uint32_t* instruction_data);
mips_error mips_decode_I(const uint32_t& instruction, uint32_t* instruction_data);
mips_error mips_decode_J(const uint32_t& instruction, uint32_t* instruction_data);

#endif
