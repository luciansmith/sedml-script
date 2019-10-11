#include <cassert>
#include <clocale>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string.h>
#include <locale.h>

#include "sedml-script-api.h"
#include "sedml-script-namespace.h"
#include "registry.h"


#ifdef _MSC_VER
#  define strdup _strdup
#endif

using namespace std;
extern int sed_yylloc_last_line;
SEDMLSCRIPT_CPP_NAMESPACE_BEGIN

//Exported routines:

LIB_EXTERN char* convertFile(const char* filename)
{
  string oldlocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "C");
  char* ret = g_registry.convertFile(filename);
  setlocale(LC_ALL, oldlocale.c_str());
  return ret;
}

LIB_EXTERN char* convertString(const char* model)
{
  string oldlocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "C");
  char* ret = g_registry.convertString(model);
  setlocale(LC_ALL, oldlocale.c_str());
  return ret;
}


LIB_EXTERN char* getLastSedmlScriptError()
{
  return g_registry.getCharStar((g_registry.getError()).c_str());
}

LIB_EXTERN int getLastSedmlScriptErrorLine()
{
  return g_registry.getErrorLine();
}



LIB_EXTERN char* getLastSedmlScript()
{
  return g_registry.getSedmlScript();
}

LIB_EXTERN char* getLastSEDML()
{
  return g_registry.getPython();
}

//LIB_EXTERN char* getSedmlScriptWarnings()
//{
//  string ret;
//  vector<string> warnings = g_registry.getSedmlScript();
//  if (warnings.size() == 0) return NULL;
//  for (size_t warn=0; warn<warnings.size(); warn++) {
//    if (warn > 0) {
//      ret += "\n";
//    }
//    ret += warnings[warn];
//  }
//  return g_registry.getCharStar(ret.c_str());
//}
//
LIB_EXTERN void freeAllSedmlScript()
{
  g_registry.freeAllSedMLScript();
}

SEDMLSCRIPT_CPP_NAMESPACE_END
