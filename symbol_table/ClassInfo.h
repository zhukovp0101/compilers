#pragma once

#include "BaseIncludes.h"

class ClassInfo {
public:
  std::unordered_map<std::string, int64_t> offsets_; // VarName : offset
  int64_t size_;
};