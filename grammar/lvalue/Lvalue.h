#pragma once

#include <base_elements/BaseElement.h>
#include "../types/Type.h"
class Lvalue: public BaseElement {
public:
  virtual void Set(const std::shared_ptr<Type>& value) = 0;
};

