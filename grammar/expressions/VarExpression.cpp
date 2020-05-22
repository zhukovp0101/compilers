#include "VarExpression.h"
#include "../types/detail.h"

VarExpression::VarExpression(std::string_view type)
    : type_(type) {}

//int VarExpression::eval() const { return first->eval() - second->eval(); }

void VarExpression::Accept(Visitor *visitor) { visitor->Visit(this); }
std::shared_ptr<Type> VarExpression::eval() const {
  return CreateVar(type_);
}
