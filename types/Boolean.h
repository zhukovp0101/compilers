#pragma once

#include "Type.h"
class Boolean: public Type {
public:
  operator int();
  std::string ToString() override;
  Boolean(bool value);
private:
  bool value_;
};

