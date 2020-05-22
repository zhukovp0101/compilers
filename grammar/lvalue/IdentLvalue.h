#pragma once

#include "BaseIncludes.h"
#include "Lvalue.h"
#include <types/Type.h>

class IdentLvalue: public Lvalue {
public:
  explicit IdentLvalue(std::string_view identifier);
  void Accept(Visitor *visitor) override;
  void Set(const std::shared_ptr<Type>& value) override;

  std::string identifier_;
};

