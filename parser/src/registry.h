#ifndef REGISTRY_H
#define REGISTRY_H

#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include "sedml-script-namespace.h"
//
//#include "sedml/SedTypes.h"
//#include "sbml/math/L3ParserSettings.h"

SEDMLSCRIPT_CPP_NAMESPACE_BEGIN

class Registry
{
private:
  std::set<std::string>    m_variablenames;
  std::string              m_error;
  int                      m_errorLine;
  std::vector<std::string> m_warnings;

  std::string              m_workingDirectory;

  //The actual SEDML bits:
  //std::vector<SedmlScriptModel>        m_models;
  //std::vector<SedmlScriptSimulation*>  m_simulations;
  //std::vector<SedmlScriptTask>         m_tasks;
  //std::vector<SedmlScriptRepeatedTask> m_repeatedTasks;
  //std::vector<SedmlScriptOutput>       m_outputs;

  //Any saved SBML documents the user has set:
  //std::map<std::string, SBMLDocument*> m_referencedSBML;

  //L3ParserSettings         m_l3ps;

public:
  Registry();
  ~Registry();

  std::istream* input;
  std::vector<int> indents;
  bool midline;
  int currIndent = 0;

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

  std::string getError() {return m_error;};
  int getErrorLine() {return m_errorLine;};
  std::vector<std::string> getScriptWarnings() {return m_warnings;};

  bool addEquals(std::vector<const std::string*>* name, std::vector<std::string>* value);
  bool startBlock(std::vector<const std::string*>* name, std::vector<std::string>* value);
  bool endBlock();

  //Setting the 'name' attribute
  bool setName(std::vector<const std::string*>* id, std::vector<const std::string*>* is, const std::string* name);

  //Assistance functions
  std::string ftoa(double val);
  const std::string* addWord(std::string word);

  //ASTNode* parseFormula(const std::string& formula);

  //When we're done, make sure the whole thing is coherent.
  bool finalize();

  //Keeping track of malloc'd stuff so we can free it ourselves if need be.
  std::vector<char*>    m_charstars;
  void freeAllSedMLScript();

  char* getCharStar(const char* orig);

private:
  bool parseInput();
  void createPython();

  bool checkId(std::vector<const std::string*>* name);
  bool isValidSId(std::vector<const std::string*>* name);
  void clearAll();

  bool file_exists (const std::string& filename);

};

SEDMLSCRIPT_CPP_NAMESPACE_END

extern SEDMLSCRIPT_CPP_NAMESPACE_QUALIFIER Registry g_registry;

#endif //REGISTRY_H