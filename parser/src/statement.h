#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <vector>
#include "enums.h"

class Statement
{
private:
  statement_type m_type;
  std::string m_target;
  std::string m_formula;
  std::vector<Statement> m_statements;

public:
  Statement();
  ~Statement();

  bool setType(statement_type type);
  bool setTarget(std::string target);
  bool setFormula(std::string formula);
  bool addStatement(Statement statement);
  bool removeStatement(size_t n);

  statement_type getType() const;
  std::string getTarget() const;
  std::string getFormula() const;
  size_t getNumStatements() const;
  Statement getStatement(size_t n) const;

};


#endif //STATEMENT_H
