#include <cassert>
#include <vector>
#include <string>
#include <cstdlib>
#include <sys/stat.h>
#include <fstream>
#include <iostream>

#include "registry.h"
#include "stringx.h"
#include "enums.h"

extern int sed_yyparse();
extern int sed_yylloc_last_line;

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
  , input(NULL)
  , indents()
  , midline(false)
  , currIndent(0)
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
  return NULL;
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
  return NULL;
}

bool Registry::addEquals(std::vector<const std::string*>* name, std::vector<std::string>* value)
{
  cout << "Parsing an equals line." << endl;
  return false;
}

bool Registry::startBlock(std::vector<const std::string*>* name, std::vector<std::string>* value)
{
  string namestr = getStringFrom(name);
  block_type btype = getBlockTypeFrom(namestr);
  if (btype == btUnknown) {
    string err = "Invalid syntax:  Unable to define a block with '" + namestr + "' and a colon: the only legal keywords are 'for', 'if' and 'def'.";
    setError(err, sed_yylloc_last_line);
  }
  cout << "Parsing a start block." << endl;
  return false;
}

bool Registry::endBlock()
{
  cout << "End of block." << endl;
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

SEDMLSCRIPT_CPP_NAMESPACE_END