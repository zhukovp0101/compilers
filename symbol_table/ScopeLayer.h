#pragma once

#include "Symbol.h"
#include "types/Type.h"


#include <grammar/statements/Declaration.h>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include "../grammar/statements/VarDecl.h"

class ScopeLayer {
 public:
    ScopeLayer();
    ~ScopeLayer();
    void AddVariable(VarDecl* declaration);
    void Put(const Symbol& symbol, std::shared_ptr<Type> value);
    std::shared_ptr<Type> Get(const Symbol& symbol);
    bool Has(const Symbol& symbol);

    static ScopeLayer* current_;
private:
  std::unordered_map<Symbol, std::shared_ptr<Type>> values_;
  bool private_ = false;
  ScopeLayer*parent_ = nullptr;
//    std::string name_;
};