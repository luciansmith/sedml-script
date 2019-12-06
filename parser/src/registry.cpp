#include <cassert>
#include <vector>
#include <string>
#include <cstdlib>
#include <sys/stat.h>
#include <fstream>
#include <iostream>

#include "registry.h"
#include "stringx.h"
#include "statement.h"
#include "enums.h"
#include <sbml/math/ASTNode.h>

extern int sed_yyparse();
extern int sed_yylloc_last_line;
extern void sed_yyerror(char const *s);


#ifdef _MSC_VER
#  define strdup _strdup
#endif


using namespace std;
SEDMLSCRIPT_CPP_NAMESPACE_BEGIN

Registry::Registry()
  : m_variablenames()
  , m_error("")
  , m_errorLine(0)
  , m_warnings()
  , m_workingDirectory("")
  , m_statements()
  , m_currStatements()
  , m_usedNodes()
  , m_hasInf(false)
  , m_hasNaN(false)
  , m_python_library(pl_roadrunner)
  , input(NULL)
  , indents()
  , midline(false)
  , currIndent(0)
  , m_indent("   ")
  , m_python_header("")
{
}

Registry::~Registry()
{
  clearAll();
}

char* Registry::convertString(string model)
{
  istringstream* inputstring = new istringstream(model + "\n");
  sed_yylloc_last_line = 1;
  currIndent = 0;
  m_error = "";
  input = inputstring;
  if (parseInput()) {
    return NULL;
  }
  createPython();
  return getPython();

  return NULL;
}

char * Registry::getSedmlScript() const
{
  return NULL;
}

char * Registry::getPython() const
{
  string full = m_python_header + m_sedml_script;
  return g_registry.getCharStar(full.c_str());
}

string Registry::getIndent() const
{
  return m_indent;
}

char* Registry::convertFile(const string& filename)
{
  string file = filename;
  if (!file_exists(file)) {
    file = m_workingDirectory + file;
    if (!file_exists(file)) {
      string error = "Input file '";
      error += filename;
      error += "' cannot be found.  Check to see if the file exists and that the permissions are correct, and try again.  If this still does not work, contact us letting us know how you got this error.";
      setError(error, 0);
      return NULL;
    }
  }
  string old_wd = m_workingDirectory;
  m_workingDirectory = file;
  size_t lastslash = m_workingDirectory.rfind('/');
  if (lastslash==string::npos) {
    lastslash = m_workingDirectory.rfind('\\');
  }
  if (lastslash!=string::npos) {
    m_workingDirectory.erase(lastslash+1, m_workingDirectory.size()-lastslash-1);
  }
  clearAll();
  ifstream* inputfile = new ifstream();
  inputfile->open(file.c_str(), ios::in);
  if (!inputfile->is_open() || !inputfile->good()) {
    string error = "Input file '";
    error += filename;
    error += "' cannot be read.  Check to see if the file exists and that the permissions are correct, and try again.  If this still does not work, contact us letting us know how you got this error.";
    setError(error, 0);
    delete inputfile;
    return NULL;
  }
  input = inputfile;
  sed_yylloc_last_line = 1;
  if (parseInput()) {
    return NULL;
  }
  createPython();
  char* ret = getPython();
  m_workingDirectory = old_wd;
  return ret;
}

bool Registry::addEquals(std::vector<const std::string*>* name, ASTNode* value)
{
  Statement statement;
  statement.setType(stEquals);
  statement.setTarget(name);
  statement.setFormula(value);
  addStatement(statement);
//  m_statements.push_back(statement);
  cout << "Parsing an equals line." << endl;
  return false;
}

bool Registry::startBlock(std::vector<const std::string*>* name, ASTNode* value)
{
  cout << "Parsing a start block." << endl;
  string namestr = getStringFrom(name);
  block_type btype = getBlockTypeFrom(namestr);
  Statement statement;
  switch (btype) {
  case btDef:
    statement.setType(stBlockDef);
    break;
  case btFor:
    statement.setType(stBlockFor);
    break;
  case btIf:
    statement.setType(stBlockIf);
    break;
  case btUnknown:
  {
    string err = "Invalid syntax:  Unable to define a block with '" + namestr + "' and a colon: the only legal keywords are 'for', 'if' and 'def'.";
    setError(err, sed_yylloc_last_line);
    return true;
  }
  }
  statement.setFormula(value);
  startBlock(statement);
  return false;
}

bool Registry::endBlock()
{
  cout << "End of block." << endl;
  if (m_currStatements.size() == 0) {
    string err = "Invalid syntax:  Unable to end a block that has not been started.";
    setError(err, sed_yylloc_last_line);
    return true;
  }
  Statement last = m_currStatements.back();
  m_currStatements.pop_back();
  addStatement(last);
  return false;
}

bool Registry::isDef(std::vector<const std::string*>* name) const
{
  return false;
}

bool Registry::setName(vector<const string*>* id, vector<const string*>* is, const string* name)
{
  string idstr = getStringFrom(id);
  string isstr = getStringFrom(is);
  stringstream err;
  return true;
}


//Assistance functions
string Registry::ftoa(double val)
{
  stringstream ret;
  ret << val;
  return ret.str();
}


const string* Registry::addWord(string word)
{
  pair<set<string>::iterator,bool> ret;

  ret = m_variablenames.insert(word);
  set<string>::iterator wordit = ret.first;
  return &(*wordit);
}

void Registry::addNodesFrom(ASTNode * node)
{
  ASTNodeType_t type = node->getType();
  m_usedNodes.insert(type);
  for (unsigned int c = 0; c < node->getNumChildren(); c++) {
    addNodesFrom(node->getChild(c));
  }
  if (node->isInfinity()) {
    m_hasInf = true;
  }
  if (node->isNaN()) {
    m_hasNaN = true;
  }
}

bool Registry::finalize()
{

  return false;
}

void Registry::freeAllSedMLScript()
{
  for (size_t i=0; i<m_charstars.size(); i++) {
    free(m_charstars[i]);
  }
  m_charstars.clear();
}


bool Registry::parseInput()
{
  clearAll();
  int success = sed_yyparse();
  if (success != 0) {
    if (getError().empty()) {
      assert(false); //Need to fill in the reason why we failed explicitly, if possible.
      if (success == 1) {
        setError("Parsing failed because of invalid input.", sed_yylloc_last_line);
      }
      else if (success == 2) {
        setError("Parsing failed due to memory exhaution.", sed_yylloc_last_line-1);
      }
      else {
        setError("Unknown parsing error.", sed_yylloc_last_line-1);
      }
    }
    return true;
  }
  return false;
}

void Registry::createPython()
{
  createSedmlScript();
  m_python_header = "# -*- coding: utf-8 -*-\n";
  m_python_header += "\"\"\"\n";
  m_python_header += "\n";
  m_python_header += "Created by libsedmlscript ";
  m_python_header += LIBSEDMLSCRIPT_VERSION_STRING;
  m_python_header += "\n";
  m_python_header += "\"\"\"\n";
  m_python_header += "\n";
  m_python_header += "";

  switch (m_python_library) {
  case pl_roadrunner:
    m_python_header += "from sed_roadrunner import model, task, plot\n\n";
  }
  string mathline = "from math import";
  string mpmathline = "from mpmath import";
  string avogadroline = "";
  string piecewise = "";
  for (set<ASTNodeType_t>::iterator type = m_usedNodes.begin(); type != m_usedNodes.end(); type++) {
    switch (*type) {
    case AST_NAME_AVOGADRO:
      avogadroline += "avogadro = 6.02214179e+23";
      break;
    case AST_CONSTANT_E:
      mathline += ", e as exponentiale";
      break;
    case AST_CONSTANT_PI:
      mathline += ", pi";
      break;
    case AST_FUNCTION_ARCCOS:
      mathline += ", acos";
      break;
    case AST_FUNCTION_ARCCOSH:
      mathline += ", acosh";
      break;
    case AST_FUNCTION_ARCCOT:
      mathline += ", acot";
      break;
    case AST_FUNCTION_ARCCOTH:
      mpmathline += ", acoth";
      break;
    case AST_FUNCTION_ARCCSC:
      mpmathline += ", acsc";
      break;
    case AST_FUNCTION_ARCCSCH:
      mpmathline += ", acsch";
      break;
    case AST_FUNCTION_ARCSEC:
      mpmathline += ", asec";
      break;
    case AST_FUNCTION_ARCSECH:
      mpmathline += ", asech";
      break;
    case AST_FUNCTION_ARCSIN:
      mathline += ", asin";
      break;
    case AST_FUNCTION_ARCSINH:
      mathline += ", asinh";
      break;
    case AST_FUNCTION_ARCTAN:
      mathline += ", atan";
      break;
    case AST_FUNCTION_ARCTANH:
      mathline += ", atanh";
      break;
    case AST_FUNCTION_CEILING:
      mathline += ", ceil";
      break;
    case AST_FUNCTION_COS:
      mathline += ", cos";
      break;
    case AST_FUNCTION_COSH:
      mathline += ", cosh";
      break;
    case AST_FUNCTION_COT:
      mpmathline += ", cot";
      break;
    case AST_FUNCTION_COTH:
      mpmathline += ", coth";
      break;
    case AST_FUNCTION_CSC:
      mpmathline += ", csc";
      break;
    case AST_FUNCTION_CSCH:
      mpmathline += ", csch";
      break;
    case AST_FUNCTION_EXP:
      mathline += ", exp";
      break;
    case AST_FUNCTION_FACTORIAL:
      mathline += ", factorial";
      break;
    case AST_FUNCTION_FLOOR:
      mathline += ", floor";
      break;
    case AST_FUNCTION_LN:
    case AST_FUNCTION_LOG:
      mathline += ", log";
      break;
    case AST_FUNCTION_SEC:
      mpmathline += ", sec";
      break;
    case AST_FUNCTION_SECH:
      mpmathline += ", sech";
      break;
    case AST_FUNCTION_SIN:
      mathline += ", sin";
      break;
    case AST_FUNCTION_SINH:
      mathline += ", sinh";
      break;
    case AST_FUNCTION_TAN:
      mathline += ", tan";
      break;
    case AST_FUNCTION_TANH:
      mathline += ", tanh";
      break;
    case AST_FUNCTION_PIECEWISE:
      piecewise = 
        "def piecewise(*args):\n"
        "    halfargs = round(len(args)/2 - 0.25)\n"
        "    for x in range(halfargs):\n"
        "        if args[x*2+1]:\n"
        "            return args[x*2]\n"
        "    if len(args)>halfargs*2:\n"
        "        return args[-1]\n"
        "    return None\n";
      break;
    }
  }
  if (m_hasInf) {
    mathline += ", inf as INF";
  }
  if (m_hasNaN) {
    mathline += ", nan as NaN";
  }
  if (mathline.find("import,") != string::npos) {
    mathline.replace(17, 1, "");
    m_python_header += mathline + "\n";
  }
  if (mpmathline.find("import,") != string::npos) {
    mpmathline.replace(19, 1, "");
    m_python_header += mpmathline + "\n";
  }
  if (avogadroline.size() > 0) {
    m_python_header += "\n" + avogadroline + "\n";
  }
  if (piecewise.size() > 0) {
    m_python_header += "\n";
    m_python_header += piecewise + "\n";
  }



  m_python_header += "#----------------------------------------------\n\n";
}

void Registry::createSedmlScript()
{
  m_sedml_script = "";
  string indent = "";
  for (size_t snum = 0; snum < m_statements.size(); snum++) {
    m_sedml_script += m_statements[snum].getSedmlScript(indent);
  }

}

bool Registry::checkId(vector<const string*>* name)
{
  stringstream err;
  err << "Unable to parse line " << sed_yylloc_last_line-1 << ": ";
  if (name->size()==0) {
    assert(false); //This shouldn't be possible, and I want to see what happened to cause it if it happens.
    err << "a phraSED-ML top-level ID must exist, and this construct has no corresponding ID.";
    setError(err.str(), sed_yylloc_last_line-1);
    return true;
  }
  else if (name->size() > 1) {
    err << "the phraSED-ML ID '" << getStringFrom(name) << "' in this context may not be a sub-id of another variable.";
    setError(err.str(), sed_yylloc_last_line-1);
    return true;
  }
  else if (!isValidSId(name)) {
    err << "a phraSED-ML id must adhere to the pattern '[A-Za-z_][A-Za-z_0-9]*', and '" << (*(*name)[0]) << " does not conform.";
    setError(err.str(), sed_yylloc_last_line-1);
    return true;
  }
  return false;
}


bool Registry::isValidSId(vector<const string*>* name)
{
  if (name->size() != 1) return false;

  //Taken from libsbml's "SyntaxChecker::isValidInternalSId(string sid)"
  size_t size = (*name)[0]->size();
  if (size == 0)
  {
    return false;
  }

  size_t n = 0;

  char c = (*(*name)[0])[n];
  bool okay = (isalpha(c) || (c == '_'));
  n++;

  while (okay && n < size)
  {
    c = (*(*name)[0])[n];
    okay = (isalnum(c) || c == '_');
    n++;
  }

  return okay;
}

void Registry::clearAll()
{
  m_error.clear();
  m_errorLine = 0;
  m_warnings.clear();
  m_currStatements.clear();
  m_statements.clear();
  m_usedNodes.clear();
  m_hasInf = false;
  m_hasNaN = false;
}

bool Registry::file_exists (const string& filename)
{
#ifdef _MSC_VER
#  define stat _stat
#endif

  if (filename.empty()) return false;
  struct stat buf;
  return stat(filename.c_str(), &buf) == 0;
}

void Registry::addStatement(const Statement & statement)
{
  if (m_currStatements.size() == 0) {
    m_statements.push_back(statement);
  }
  else {
    m_currStatements[m_currStatements.size() - 1].addStatement(statement);
  }
}

void Registry::startBlock(const Statement & statement)
{
  m_currStatements.push_back(statement);
}

//Useful functions for later routines:
char* Registry::getCharStar(const char* orig)
{
  char* ret = strdup(orig);
  if (ret == NULL) {
    setError("Out of memory error.", sed_yylloc_last_line-1);
    return NULL;
  }
  m_charstars.push_back(ret);
  return ret;
}

ASTNodeType_t Registry::getSymbolFor(string name) const
{
  if (l3StrCmp(name, "True"))         return AST_CONSTANT_TRUE;
  if (l3StrCmp(name, "False"))        return AST_CONSTANT_FALSE;
  if (l3StrCmp(name, "pi"))           return AST_CONSTANT_PI;
  if (l3StrCmp(name, "exponentiale")) return AST_CONSTANT_E;
  if (l3StrCmp(name, "avogadro"))     return AST_NAME_AVOGADRO;
  if (l3StrCmp(name, "time"))         return AST_NAME_TIME;
  if (l3StrCmp(name, "inf"))          return AST_REAL;
  if (l3StrCmp(name, "infinity"))     return AST_REAL;
  if (l3StrCmp(name, "nan"))          return AST_REAL;
  if (l3StrCmp(name, "notanumber"))   return AST_REAL;
  return AST_UNKNOWN;
}

ASTNodeType_t Registry::getFunctionFor(string name) const
{
  //Python native functions:
  if (l3StrCmp(name, "abs"))      return AST_FUNCTION_ABS;
  if (l3StrCmp(name, "pow"))      return AST_POWER;
  if (l3StrCmp(name, "not"))      return AST_LOGICAL_NOT;

  //Extended Python functions:
  if (l3StrCmp(name, "acos"))     return AST_FUNCTION_ARCCOS;
  if (l3StrCmp(name, "arccos"))   return AST_FUNCTION_ARCCOS;
  if (l3StrCmp(name, "acosh"))    return AST_FUNCTION_ARCCOSH;
  if (l3StrCmp(name, "arccosh"))  return AST_FUNCTION_ARCCOSH;
  if (l3StrCmp(name, "acot"))     return AST_FUNCTION_ARCCOT;
  if (l3StrCmp(name, "arccot"))   return AST_FUNCTION_ARCCOT;
  if (l3StrCmp(name, "acoth"))    return AST_FUNCTION_ARCCOTH;
  if (l3StrCmp(name, "arccoth"))  return AST_FUNCTION_ARCCOTH;
  if (l3StrCmp(name, "acsc"))     return AST_FUNCTION_ARCCSC;
  if (l3StrCmp(name, "arccsc"))   return AST_FUNCTION_ARCCSC;
  if (l3StrCmp(name, "acsch"))    return AST_FUNCTION_ARCCSCH;
  if (l3StrCmp(name, "arccsch"))  return AST_FUNCTION_ARCCSCH;
  if (l3StrCmp(name, "asec"))     return AST_FUNCTION_ARCSEC;
  if (l3StrCmp(name, "arcsec"))   return AST_FUNCTION_ARCSEC;
  if (l3StrCmp(name, "asech"))    return AST_FUNCTION_ARCSECH;
  if (l3StrCmp(name, "arcsech"))  return AST_FUNCTION_ARCSECH;
  if (l3StrCmp(name, "asin"))     return AST_FUNCTION_ARCSIN;
  if (l3StrCmp(name, "arcsin"))   return AST_FUNCTION_ARCSIN;
  if (l3StrCmp(name, "asinh"))    return AST_FUNCTION_ARCSINH;
  if (l3StrCmp(name, "arcsinh"))  return AST_FUNCTION_ARCSINH;
  if (l3StrCmp(name, "atan"))     return AST_FUNCTION_ARCTAN;
  if (l3StrCmp(name, "arctan"))   return AST_FUNCTION_ARCTAN;
  if (l3StrCmp(name, "atanh"))    return AST_FUNCTION_ARCTANH;
  if (l3StrCmp(name, "arctanh"))  return AST_FUNCTION_ARCTANH;
  if (l3StrCmp(name, "ceil"))     return AST_FUNCTION_CEILING;
  if (l3StrCmp(name, "ceiling"))  return AST_FUNCTION_CEILING;
  if (l3StrCmp(name, "cos"))      return AST_FUNCTION_COS;
  if (l3StrCmp(name, "cosh"))     return AST_FUNCTION_COSH;
  if (l3StrCmp(name, "cot"))      return AST_FUNCTION_COT;
  if (l3StrCmp(name, "coth"))     return AST_FUNCTION_COTH;
  if (l3StrCmp(name, "csc"))      return AST_FUNCTION_CSC;
  if (l3StrCmp(name, "csch"))     return AST_FUNCTION_CSCH;
  if (l3StrCmp(name, "delay"))    return AST_FUNCTION_DELAY;
  if (l3StrCmp(name, "exp"))      return AST_FUNCTION_EXP;
  if (l3StrCmp(name, "factorial")) return AST_FUNCTION_FACTORIAL;
  if (l3StrCmp(name, "floor"))    return AST_FUNCTION_FLOOR;
  if (l3StrCmp(name, "lambda"))   return AST_LAMBDA;
  if (l3StrCmp(name, "log"))      return AST_FUNCTION_LOG;
  if (l3StrCmp(name, "ln"))       return AST_FUNCTION_LN;
  if (l3StrCmp(name, "log10"))    return AST_FUNCTION_LOG;
  if (l3StrCmp(name, "piecewise")) return AST_FUNCTION_PIECEWISE;
  if (l3StrCmp(name, "power"))    return AST_POWER;
  if (l3StrCmp(name, "sqr"))      return AST_FUNCTION_POWER;
  if (l3StrCmp(name, "sqrt"))     return AST_FUNCTION_ROOT;
  if (l3StrCmp(name, "root"))     return AST_FUNCTION_ROOT;
  if (l3StrCmp(name, "sec"))      return AST_FUNCTION_SEC;
  if (l3StrCmp(name, "sech"))     return AST_FUNCTION_SECH;
  if (l3StrCmp(name, "sin"))      return AST_FUNCTION_SIN;
  if (l3StrCmp(name, "sinh"))     return AST_FUNCTION_SINH;
  if (l3StrCmp(name, "tan"))      return AST_FUNCTION_TAN;
  if (l3StrCmp(name, "tanh"))     return AST_FUNCTION_TANH;

  //Functions that worked in SBML, but not in Python:
  //if (l3StrCmp(name, "divide"))   return AST_DIVIDE;
  //if (l3StrCmp(name, "minus"))    return AST_MINUS;
  //if (l3StrCmp(name, "plus"))     return AST_PLUS;
  //if (l3StrCmp(name, "times"))    return AST_TIMES;
  //if (l3StrCmp(name, "eq"))       return AST_RELATIONAL_EQ;
  //if (l3StrCmp(name, "equals"))   return AST_RELATIONAL_EQ;
  //if (l3StrCmp(name, "geq"))      return AST_RELATIONAL_GEQ;
  //if (l3StrCmp(name, "gt"))       return AST_RELATIONAL_GT;
  //if (l3StrCmp(name, "leq"))      return AST_RELATIONAL_LEQ;
  //if (l3StrCmp(name, "lt"))       return AST_RELATIONAL_LT;
  //if (l3StrCmp(name, "neq"))      return AST_RELATIONAL_NEQ;
  //if (l3StrCmp(name, "xor"))      return AST_LOGICAL_XOR;

  //Python-native syntax: can't use as functions.
  //if (l3StrCmp(name, "and"))      return AST_LOGICAL_AND;
  //if (l3StrCmp(name, "or"))       return AST_LOGICAL_OR;
  return AST_UNKNOWN;
}

bool Registry::l3StrCmp(const string& lhs, const string& rhs) const
{
  return lhs==rhs;
}

bool Registry::checkNumArguments(const ASTNode* function)
{
  unsigned int children = function->getNumChildren();
  stringstream error;
  string name = "";
  if (function->isOperator()) {
    name = function->getOperatorName();
  }
  else {
    name = function->getName();
  }
  error << "The function '" << name << "' takes ";
  string errmsg = "";
  ASTNodeType_t type = function->getType();
  switch (type)
  {
  case AST_FUNCTION_ABS:
  case AST_FUNCTION_ARCCOS:
  case AST_FUNCTION_ARCCOSH:
  case AST_FUNCTION_ARCCOT:
  case AST_FUNCTION_ARCCOTH:
  case AST_FUNCTION_ARCCSC:
  case AST_FUNCTION_ARCCSCH:
  case AST_FUNCTION_ARCSEC:
  case AST_FUNCTION_ARCSECH:
  case AST_FUNCTION_ARCSIN:
  case AST_FUNCTION_ARCSINH:
  case AST_FUNCTION_ARCTAN:
  case AST_FUNCTION_ARCTANH:
  case AST_FUNCTION_CEILING:
  case AST_FUNCTION_COS:
  case AST_FUNCTION_COSH:
  case AST_FUNCTION_COT:
  case AST_FUNCTION_COTH:
  case AST_FUNCTION_CSC:
  case AST_FUNCTION_CSCH:
  case AST_FUNCTION_EXP:
  case AST_FUNCTION_FACTORIAL:
  case AST_FUNCTION_FLOOR:
  case AST_FUNCTION_LN:
  case AST_FUNCTION_SEC:
  case AST_FUNCTION_SECH:
  case AST_FUNCTION_SIN:
  case AST_FUNCTION_SINH:
  case AST_FUNCTION_TAN:
  case AST_FUNCTION_TANH:
  case AST_LOGICAL_NOT:

    if (children != 1) {
      error << "exactly one argument, but " << children << " were found.";
      sed_yyerror(error.str().c_str());
      delete function;
      return true;
    }
    return false;
  case AST_DIVIDE:
  case AST_FUNCTION_DELAY:
  case AST_FUNCTION_LOG:       // a log ASTNode has a child for base
  case AST_FUNCTION_POWER:
  case AST_POWER:
  case AST_RELATIONAL_NEQ:

    if (children != 2) {
      error << "exactly two arguments, but " << children << " were found.";
      sed_yyerror(error.str().c_str());
      delete function;
      return true;
    }
    return false;

  case AST_RELATIONAL_EQ:
  case AST_RELATIONAL_GEQ:
  case AST_RELATIONAL_GT:
  case AST_RELATIONAL_LEQ:
  case AST_RELATIONAL_LT:
    if (children <= 1) {
      error << "at least two arguments, but " << children << " were found.";
      sed_yyerror(error.str().c_str());
      delete function;
      return true;
    }
    return false;

  case AST_FUNCTION_PIECEWISE:
  case AST_LAMBDA:
    if (children == 0) {
      error << "at least one argument, but none were found.";
      sed_yyerror(error.str().c_str());
      delete function;
      return true;
    }
    return false;

  case AST_FUNCTION_ROOT:
  case AST_MINUS:
    if (children < 1 || children > 2) {
      error << "exactly one or two arguments, but " << children << " were found.";
      sed_yyerror(error.str().c_str());
      delete function;
      return true;
    }
    return false;

  case AST_TIMES:
  case AST_PLUS:
  case AST_LOGICAL_AND:
  case AST_LOGICAL_OR:
  case AST_LOGICAL_XOR:
    return false;
  default:
    //Otherwise, we'll assume that the function is n-ary and takes 0 or more arguments
    return false;
  }
}

void makeConstantIntoName(ASTNodeType_t type, ASTNode* function)
{
  if (function->getType() == type) {
    function->setType(AST_NAME);
    function->setDefinitionURL("");
    switch(type) {
    case AST_CONSTANT_TRUE:
      function->setName("true");
      break;
    case AST_CONSTANT_FALSE:
      function->setName("false");
      break;
    case AST_CONSTANT_PI:
      function->setName("pi");
      break;
    case AST_CONSTANT_E:
      function->setName("exponentiale");
      break;
    default:
      break;
    }
  }
  for (unsigned int c=0; c<function->getNumChildren(); c++) {
    makeConstantIntoName(type, function->getChild(c));
  }
}

ASTNode* Registry::combineRelationalElements(ASTNode* left, ASTNode* right, ASTNodeType_t type)
{
  //If 'left' is the same as 'type', add 'right' as a new argument.  (cf x < y < z -> lt(x, y, z))
  ASTNodeType_t leftType = left->getType();
  if (leftType == type && type != AST_RELATIONAL_NEQ)
  {
    left->addChild(right);
    return left;
  }
  //If 'left' is relational itself, make a new 'and' node and combine them:
  // x < y <= z  ->  and(x<y, y<=z)
  if (ASTNode_isRelational(left))
  {
    ASTNode* ret = new ASTNode(AST_LOGICAL_AND);
    ret->addChild(left);
    ASTNode* newrel = new ASTNode(type);
    newrel->addChild(left->getChild(left->getNumChildren()-1)->deepCopy());
    newrel->addChild(right);
    ret->addChild(newrel);
    return ret;
  }

  //Another option is that we've already done the above, and need to extend it:
  if (leftType == AST_LOGICAL_AND && left->getNumChildren() >= 2)
  {
    bool combine = true;
    ASTNode* leftchild = NULL;
    for (unsigned int lc=0; lc<left->getNumChildren(); lc++)
    {
      leftchild = left->getChild(lc);
      if (!ASTNode_isRelational(leftchild) ||
        leftchild->getNumChildren() < 2)
      {
        combine = false;
      }
    }
    if (combine)
    {
      if (leftchild->getType() == type && type != AST_RELATIONAL_NEQ) {
        //We can combine them by adding to the last entry (x < y <= z <= q)
        leftchild->addChild(right);
        return left;
      }
      ASTNode* newrel = new ASTNode(type);
      newrel->addChild(leftchild->getChild(leftchild->getNumChildren()-1)->deepCopy());
      newrel->addChild(right);
      left->addChild(newrel);
      return left;
    }
  }

  //Otherwise, we can't combine them:
  ASTNode* ret = new ASTNode(type);
  ret->addChild(left);
  ret->addChild(right);
  return ret;
}




SEDMLSCRIPT_CPP_NAMESPACE_END