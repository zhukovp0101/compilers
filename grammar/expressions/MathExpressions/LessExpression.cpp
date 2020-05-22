#include "LessExpression.h"
#include <types/Boolean.h>
#include <types/Integer.h>

LessExpression::LessExpression(Expression *e1, Expression *e2): first(e1), second(e2) {}

std::shared_ptr<Type> LessExpression::eval() const {
  return std::make_shared<Boolean>(
      (int)*std::dynamic_pointer_cast<Integer>(first->eval()) <
      (int)*std::dynamic_pointer_cast<Integer>(second->eval()));
}

void LessExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
