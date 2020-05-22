#pragma once

#include "Type.h"
class ArrayType: public Type {
public:
  ArrayType(const std::string& type, size_t size): size_(size) {

  }

private:
  size_t size_;

};
