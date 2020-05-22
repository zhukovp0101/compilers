#include "EqExpression.h"

EqExpression::EqExpression(Expression *e1, Expression *e2): first(e1), second(e2) {}

std::shared_ptr<Type> EqExpression::eval() const {
  return std::make_shared<Boolean>(
      (int)*std::dynamic_pointer_cast<Integer>(first->eval()) ==
      (int)*std::dynamic_pointer_cast<Integer>(second->eval()));
}

void EqExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
