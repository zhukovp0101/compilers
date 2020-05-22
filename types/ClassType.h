#pragma once

#include "BaseIncludes.h"

#include "Type.h"
#include "../symbol_table/ClassTable.h"
#include "../symbol_table/ScopeLayer.h"

class ClassType: public Type {
public:
  explicit ClassType(std::string_view class_name);
  std::string class_name_;
  ScopeLayer scope_layer_;
  std::string ToString() override;
};
