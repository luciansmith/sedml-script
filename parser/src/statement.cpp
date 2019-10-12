#include <cassert>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <math.h>

#include "statement.h"
#include "registry.h"
#include "stringx.h"


using namespace std;
extern bool CaselessStrCmp(const string& lhs, const string& rhs);

Statement::Statement()
  : m_type(stUnknown)
  , m_target("")
  , m_formula("")
  , m_statements()
{
}

Statement::~Statement()
{
}

bool Statement::setType(statement_type type)
{
  m_type = type;
  //Do other stuff, like checking other member variables.
  return false;
}

bool Statement::setTarget(std::string target)
{
  m_target = target;
  //Check stuff
  return false;
}

bool Statement::setFormula(std::string formula)
{
  m_formula = formula;
  //Check stuff.
  return false;
}

bool Statement::addStatement(Statement statement)
{
  m_statements.push_back(statement);
  //Check things??
  return false;
}

bool Statement::removeStatement(size_t n)
{
  if (m_statements.size() <= n) {
    //Set an error
    g_registry.setError("Cannot remove statement because there are not that many statements.", 0);
    return true;
  }
  return false;
}

statement_type Statement::getType() const
{
  return m_type;
}

std::string Statement::getTarget() const
{
  return m_target;
}

std::string Statement::getFormula() const
{
  return m_formula;
}

size_t Statement::getNumStatements() const
{
  return m_statements.size();
}

Statement Statement::getStatement(size_t n) const
{
  if (m_statements.size() >= n) {
    g_registry.setError("Not enough statements: returning blank.", 0);
    return Statement();
  }
  return m_statements[n];
}
