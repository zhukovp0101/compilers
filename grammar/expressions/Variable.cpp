//
// Created by bevertax on 02.04.2020.
//

#include "Variable.h"
#include "../types/detail.h"
Variable::Variable(std::string_view type): type_(type) {}
void Variable::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
std::shared_ptr<Type> Variable::eval() const { return CreateVar(type_); }
