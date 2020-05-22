#pragma once

#include "Declaration.h"
#include "Statement.h"
#include "expressions/Expression.h"

#include <string>
#include <string_view>

class VarDecl: public Declaration {
 public:
    VarDecl(std::string_view type, std::string_view identifier);
    void Accept(Visitor *visitor) override;

    std::string type_;
};