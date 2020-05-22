//
// Created by bevertax on 02.04.2020.
//

#include "Boolean.h"
Boolean::operator int() { return value_; }
Boolean::Boolean(bool value): value_(value) {}
std::string Boolean::ToString() { return "bool"; }
