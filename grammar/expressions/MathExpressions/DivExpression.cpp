#include "DivExpression.h"

DivExpression::DivExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}

std::shared_ptr<Type> DivExpression::eval() const {
  return std::make_shared<Integer>(
      (int)*std::dynamic_pointer_cast<Integer>(first->eval()) /
      (int)*std::dynamic_pointer_cast<Integer>(second->eval()));
}

void DivExpression::Accept(Visitor *visitor) { visitor->Visit(this); }