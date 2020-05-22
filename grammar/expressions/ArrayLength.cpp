//
// Created by bevertax on 02.04.2020.
//

#include "ArrayLength.h"
#include <types/Integer.h>
#include "types/Array.h"

ArrayLength::ArrayLength(Expression* array): array_(array) {

}
std::shared_ptr<Type> ArrayLength::eval() const {
  return std::make_shared<Integer>(0);
}
void ArrayLength::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
