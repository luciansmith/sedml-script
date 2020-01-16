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
  ASTNode*                  m_target;
  ASTNode*                  m_formula;
  ASTNode*                  m_selector;
  std::vector<Statement>    m_statements;

public:
  Statement();
  ~Statement();

  bool setType(statement_type type);
  bool setTarget(ASTNode* target);
  bool setFormula(ASTNode* formula);
  bool setSelector(ASTNode * selector);
  bool addStatement(Statement statement);
  std::string getSedmlScript(std::string indent);

  statement_type getType() const;
  statement_type getLastChildType() const;
  ASTNode* getTarget() const;
  ASTNode* getFormula() const;
  size_t getNumStatements() const;
  Statement getStatement(size_t n) const;

};


#endif //STATEMENT_H
