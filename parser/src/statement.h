#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <vector>
#include "enums.h"
class ASTNode;

class Statement
{
private:
  statement_type            m_type;
  std::vector<std::string>  m_target;
  ASTNode*                  m_formula;
  std::vector<Statement>    m_statements;

public:
  Statement();
  ~Statement();

  bool setType(statement_type type);
  bool setTarget(std::vector<std::string> target);
  bool setTarget(std::vector<const std::string*>* target);
  bool setFormula(ASTNode* formula);
  bool addStatement(Statement statement);
  std::string getSedmlScript(std::string indent);

  statement_type getType() const;
  std::vector<std::string> getTarget() const;
  ASTNode* getFormula() const;
  size_t getNumStatements() const;
  Statement getStatement(size_t n) const;

};


#endif //STATEMENT_H
