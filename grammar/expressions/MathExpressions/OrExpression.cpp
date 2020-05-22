#include "OrExpression.h"
#include <types/Boolean.h>

OrExpression::OrExpression(Expression *e1, Expression *e2): first(e1), second(e2) {}

std::shared_ptr<Type> OrExpression::eval() const {
  return std::make_shared<Boolean>(
      (int)*std::dynamic_pointer_cast<Boolean>(first->eval()) ||
      (int)*std::dynamic_pointer_cast<Boolean>(second->eval()));
}

void OrExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}