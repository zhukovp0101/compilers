#pragma once

#include "BaseIncludes.h"
#include "Expression.h"

class Array: public Expression {
public:
  Array(std::string_view type, Expression* length);
  void Accept(Visitor *visitor) override;
  std::shared_ptr<Type> eval() const override {};
  std::string type_;
  Expression* length_;
};

