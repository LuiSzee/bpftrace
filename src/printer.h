#pragma once

#include <ostream>
#include "ast.h"

namespace bpftrace {
namespace ast {

class Printer : public Visitor {
public:
  explicit Printer(std::ostream &out) : out_(out) { }

  void visit(Integer &integer) override;
  void visit(String &string) override;
  void visit(Builtin &builtin) override;
  void visit(Call &call) override;
  void visit(Map &map) override;
  void visit(Binop &binop) override;
  void visit(Unop &unop) override;
  void visit(ExprStatement &expr) override;
  void visit(AssignMapStatement &assignment) override;
  void visit(AssignMapCallStatement &assignment) override;
  void visit(Predicate &pred) override;
  void visit(Probe &probe) override;
  void visit(Program &program) override;

  int depth_ = 0;

private:
  std::ostream &out_;
};

} // namespace ast
} // namespace bpftrace
