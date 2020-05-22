#include "Integer.h"

Integer::Integer(int value): value_(value) {}
Integer::operator int() { return value_; }
std::string Integer::ToString() { return "int"; }
