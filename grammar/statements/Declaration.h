#pragma once

#include "Statement.h"
#include <string>
class Declaration: public Statement {
public:
  virtual ~Declaration() = default;
  std::string identifier_;
  void Accept(Visitor *visitor) override;
};

