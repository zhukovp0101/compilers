//
// Created by bevertax on 02.04.2020.
//

#include "Array.h"
Array::Array(std::string_view type, Expression *length): type_(type), length_(length) {}
void Array::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
