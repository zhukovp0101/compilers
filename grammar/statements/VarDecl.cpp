#include "VarDecl.h"

VarDecl::VarDecl(std::string_view type,
    std::string_view identifier
) : type_(type) {
  identifier_ = identifier;
}
void VarDecl::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
