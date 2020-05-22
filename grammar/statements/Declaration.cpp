//
// Created by bevertax on 02.04.2020.
//

#include "Declaration.h"
void Declaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
