#pragma once
//#include "base_elements/BaseElement.h"
#include "../statements/Statement.h"
#include <memory>
#include <types/Type.h>

class Expression : public Statement {
public:
    [[nodiscard]] virtual std::shared_ptr<Type> eval() const = 0;
};