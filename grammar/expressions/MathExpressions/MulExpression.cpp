#include "MulExpression.h"
#include <types/Integer.h>

MulExpression::MulExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}

std::shared_ptr<Type> MulExpression::eval() const {
  return std::make_shared<Integer>(
      (int)*std::dynamic_pointer_cast<Integer>(first->eval()) *
      (int)*std::dynamic_pointer_cast<Integer>(second->eval()));
}

void MulExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}