#pragma once

#include "Type.h"

class Integer: public Type {
 public:
    explicit Integer(int value);
    operator int();
    std::string ToString() override;

  private:
    int value_;
};