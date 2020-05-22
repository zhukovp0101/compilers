#pragma once

#include "BaseIncludes.h"
#include "Lvalue.h"
#include "../expressions/Expression.h"
#include <types/Type.h>

class LvalueArrayItem: public Lvalue {
public:
  LvalueArrayItem(std::string_view identifier, Expression* expression);
  void Accept(Visitor *visitor) override;
  void Set(const std::shared_ptr<Type> &value) override;

  std::string identifier_;
  Expression* expression_;
};

