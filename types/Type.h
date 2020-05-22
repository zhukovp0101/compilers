#pragma once

#include <memory>
#include <string>

class Type {
 public:
    virtual std::string ToString() = 0;
    virtual ~Type() = default;
};