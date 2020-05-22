#include "ModExpression.h"
#include <types/Integer.h>

ModExpression::ModExpression(Expression *e1, Expression *e2): first(e1), second(e2) {}

std::shared_ptr<Type> ModExpression::eval() const {
  return std::make_shared<Integer>(
      (int)*std::dynamic_pointer_cast<Integer>(first->eval()) %
      (int)*std::dynamic_pointer_cast<Integer>(second->eval()));
}

void ModExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
