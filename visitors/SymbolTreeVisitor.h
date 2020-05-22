#include "TemplateVisitor.h"

#include "symbol_table/Table.h"
#include <map>

#include "symbol_table/ScopeLayerTree.h"


//class SymbolTreeVisitor: public Visitor {
// public:
//    SymbolTreeVisitor();
//    ~SymbolTreeVisitor() = default;
//    void Visit(Function *function) override;
//    void Visit(Expression* expression) override;
//    void Visit(PrintStatement* statement) override;
//    void Visit(Assignment* assignment) override;
//    void Visit(VarDecl* var_decl) override;
//    void Visit(AssignmentList* assignment_list) override;
//    void Visit(ScopeAssignmentList* list) override;
//    void Visit(Program* program) override;
//    void Visit(ParamList* param_list) override;
//    void Visit(ClassDecl* class_decl) override;
//
//    ScopeLayerTree GetRoot();
//
//    std::unordered_map<Symbol, Function*> GetFunctions() const;
// private:
//    ScopeLayerTree tree_;
//    ScopeLayer* current_layer_;
//    std::unordered_map<Symbol, Function*> functions_;
//};