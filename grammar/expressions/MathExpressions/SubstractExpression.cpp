#include "SubstractExpression.h"
#include <types/Integer.h>

SubstractExpression::SubstractExpression(Expression *e1, Expression *e2): first(e1), second(e2) {}

std::shared_ptr<Type> SubstractExpression::eval() const {
  return std::make_shared<Integer>(
      (int)*std::dynamic_pointer_cast<Integer>(first->eval()) -
      (int)*std::dynamic_pointer_cast<Integer>(second->eval()));
}

void SubstractExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}