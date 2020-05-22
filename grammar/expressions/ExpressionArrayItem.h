#pragma once

#include "Expression.h"
class ExpressionArrayItem: public Expression {
public:
  ExpressionArrayItem(Expression* array, Expression* item);
  void Accept(Visitor *visitor) override;
  [[nodiscard]] std::shared_ptr<Type> eval() const override {};
  Expression* array_;
  Expression* item_;
};

