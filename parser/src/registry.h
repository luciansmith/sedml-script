#ifndef REGISTRY_H
#define REGISTRY_H

#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <sbml/math/ASTNode.h>
#include "sedml-script-namespace.h"
#include "statement.h"

SEDMLSCRIPT_CPP_NAMESPACE_BEGIN

class Registry
{
private:
  std::set<std::string>    m_variablenames;
  std::string              m_error;
  int                      m_errorLine;
  std::vector<std::string> m_warnings;
  std::string              m_workingDirectory;

  std::vector<Statement>   m_statements;
  std::vector<Statement>   m_currStatements;

  std::set<ASTNodeType_t>  m_usedNodes;
  bool                     m_hasInf;
  bool                     m_hasNaN;
  python_library           m_python_library;

public:
  Registry();
  ~Registry();

  std::istream* input;
  std::vector<int> indents;
  bool midline;
  int currIndent;

  std::string m_indent;
  std::string m_python_header;
  std::string m_sedml_script;

  char* convertFile(const std::string& filename);
  char* convertString(std::string model);

  //L3ParserSettings* getL3ParserSettings() {return &m_l3ps;};

  void setError(std::string error, int line) {m_error = error; m_errorLine=line;};
  void addErrorPrefix(std::string error) {m_error = error + m_error;};
  void addWarning(std::string warning) {m_warnings.push_back(warning);};
  void clearWarnings() {m_warnings.clear();};

  //std::string getSeparator() const {return m_separator;};

  char* getSedmlScript() const;
  char* getPython() const;

  std::string getIndent() const;

  std::string getError() {return m_error;};
  int getErrorLine() {return m_errorLine;};
  std::vector<std::string> getScriptWarnings() {return m_warnings;};

  bool addEquals(ASTNode* target, ASTNode* value);
  bool addExecute(ASTNode* value);
  bool startBlock(ASTNode* value, block_type btype);
  bool startElseBlock();
  bool startElifBlock();
  bool startForBlock(ASTNode * variables, ASTNode * from);
  bool endBlock();

  bool isDef(const std::string& name) const;

  //Setting the 'name' attribute
  bool setName(std::vector<const std::string*>* id, std::vector<const std::string*>* is, const std::string* name);

  //Assistance functions
  std::string ftoa(double val);
  const std::string* addWord(std::string word);
  void addNodesFrom(ASTNode* node);

  //ASTNode* parseFormula(const std::string& formula);

  //When we're done, make sure the whole thing is coherent.
  bool finalize();

  //Keeping track of malloc'd stuff so we can free it ourselves if need be.
  std::vector<char*>    m_charstars;
  void freeAllSedMLScript();

  char* getCharStar(const char* orig);

  ASTNodeType_t getSymbolFor(std::string name) const;

  ASTNodeType_t getFunctionFor(std::string name) const;

  bool l3StrCmp(const std::string & lhs, const std::string & rhs) const;
  bool checkNumArguments(const ASTNode * function);
  ASTNode * combineRelationalElements(ASTNode * left, ASTNode * right, ASTNodeType_t type);

private:
  bool parseInput();
  void createPython();

  void createSedmlScript();

  bool checkId(std::vector<const std::string*>* name);
  bool isValidSId(std::vector<const std::string*>* name);
  void clearAll();

  bool file_exists (const std::string& filename);

  void addStatement(const Statement& statement);
  void startBlock(const Statement& statement);

  bool lastNotIf();



};

SEDMLSCRIPT_CPP_NAMESPACE_END

extern SEDMLSCRIPT_CPP_NAMESPACE_QUALIFIER Registry g_registry;

#endif //REGISTRY_H
