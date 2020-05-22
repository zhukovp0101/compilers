#pragma once

#include "Expression.h"
class ArrayLength: public Expression {
public:
  explicit ArrayLength(Expression* array);
  void Accept(Visitor *visitor) override;
  std::shared_ptr<Type> eval() const override;
  Expression* array_;
};

