#include <cassert>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <math.h>

#include "stringx.h"
#include "statement.h"
#include "registry.h"

using namespace std;
using namespace sedmlscript;
extern bool CaselessStrCmp(const string& lhs, const string& rhs);

Statement::Statement()
  : m_type(stUnknown)
  , m_target()
  , m_formula()
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

bool Statement::setTarget(vector<string> target)
{
  m_target = target;
  //Check stuff
  return false;
}

bool Statement::setTarget(vector<const string*>* target)
{
  if (target == NULL) {
    return false;
  }
  for (size_t tnum = 0; tnum < (*target).size(); tnum++) {
    m_target.push_back(*(*target)[tnum]);
  }
  return false;
}

bool Statement::setFormula(ASTNode* formula)
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

string Statement::getSedmlScript(string indent)
{
  string ret = "";
  if (m_type == stUnknown) {
    return ret;
  }
  L3ParserSettings l3ps;
  l3ps.setPythonFormat(PythonFormatWithoutPackagesInNames);
  l3ps.setParsePackageMath(EM_REMAINING, true);
  if (m_type == stEquals) {
    ret += indent;
    ret += getStringFrom(&m_target);
    ret += " = ";
    ret += SBML_formulaToL3StringWithSettings(m_formula, &l3ps);
    ret += "\n";
    return ret;
  }
  //Otherwise it's a block:
  ret += indent;
  switch (m_type) {
  case stBlockDef:
    ret += "def ";
    break;
  case stBlockIf:
    ret += "if ";
    break;
  case stBlockFor:
    ret += "for ";
    break;
  }
  ret += SBML_formulaToL3StringWithSettings(m_formula, &l3ps);
  ret += ":\n";
  indent += g_registry.getIndent();
  for (size_t snum = 0; snum < m_statements.size(); snum++) {
    ret += m_statements[snum].getSedmlScript(indent);
  }
  return ret;
}

statement_type Statement::getType() const
{
  return m_type;
}

vector<string> Statement::getTarget() const
{
  return m_target;
}

ASTNode* Statement::getFormula() const
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
