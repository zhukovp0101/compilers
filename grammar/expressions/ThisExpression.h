#pragma once

#include "Expression.h"
class ThisExpression: public Expression {
public:
  ThisExpression();
  void Accept(Visitor *visitor) override;
  std::shared_ptr<Type> eval() const override {};
};

