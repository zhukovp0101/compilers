#include "NegativeExpression.h"
#include <types/Boolean.h>
#include <types/Integer.h>

NegativeExpression::NegativeExpression(Expression *expression): expression(expression) {}

std::shared_ptr<Type> NegativeExpression::eval() const {
  return std::make_shared<Boolean>(
      !(*std::dynamic_pointer_cast<Integer>(expression->eval())));
}

void NegativeExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}