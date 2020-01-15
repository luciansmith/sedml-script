/**
 * \file    TestBasic.c
 * \brief   Test SED-ML script's basic constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "sedml-script-api.h"
#include "sedml-script-namespace.h"
#include "registry.h"
#include "TestUtil.h"

#include <check.h>
#include <iostream>
#include <fstream>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;
SEDMLSCRIPT_CPP_NAMESPACE_USE

void compareFileTranslation(const string& base)
{
  string dir(TestDataDirectory);
  string scriptfile = dir + base + ".txt";
  string pyfile = dir + base + ".py";
  char* py_gen = convertFile(scriptfile.c_str());
  if (py_gen==NULL) {
    cout << getLastSedmlScriptError() << endl << endl;
    fail_unless(false);
    return;
  }
  //cout << "SED-ML generated from " << base << ".txt" << endl << py_gen << endl;
  //char* script_rt = getLastSedmlScript();

  fail_unless(g_registry.getError() == "");

  std::ifstream t(pyfile);
  std::stringstream buffer;
  buffer << t.rdbuf();
  fail_unless(buffer.str() == (string)py_gen);
  free(py_gen);

  //char* script_gen = convertFile(pyfile.c_str());
  //if (script_gen==NULL) {
  //  cout << getLastSedmlScriptError() << endl << endl;
  //  fail_unless(false);
  //  return;
  //}
  ////cout << "script-ML generated from " << base << ".py" << endl << script_gen << endl;
  //char* sed_rt = getLastSEDML();

  //fail_unless((string)script_rt == (string)script_gen);
  //fail_unless((string)sed_rt     == (string)py_gen);
  //if (sed_rt != py_gen) {
  //  ofstream outfile((dir + base + ".py").c_str());
  //  outfile.write(py_gen, ((string)py_gen).size());
  //  outfile.close();
  //}

  //free(sed_rt);
  //free(script_gen);
  //free(script_rt);
}

void compareStringTranslation(const string& scriptml, const string& base)
{
  string dir(TestDataDirectory);
  string pyfile = dir + base + ".py";
  string scriptfile = dir + base + ".txt";
  char* py_gen = convertString(scriptml.c_str());
  cout << "Original:" << endl << scriptml << endl;
  cout << "Translated:" << endl << py_gen << endl;

  //When creating files originally:
  //ofstream output;
  //output.open(pyfile, ios_base::out);
  //output << py_gen;
  //output.close();
  //output.open(scriptfile, ios_base::out);
  //output << scriptml << "\n";
  //output.close();

  fail_unless(g_registry.getError() == "");

  std::ifstream t(pyfile);
  std::stringstream buffer;
  buffer << t.rdbuf();
  fail_unless(buffer.str() == (string)py_gen);
  free(py_gen);

  py_gen = convertFile(scriptfile.c_str());
  fail_unless(g_registry.getError() == "");
  fail_unless(buffer.str() == (string)py_gen);
  free(py_gen);
}

void compareStringAndFileTranslation(const string& scriptml, const string& base)
{
  compareStringTranslation(scriptml, base+".py");
  compareFileTranslation(base);
}

void compareOriginalXMLTranslations(const string& base)
{
  string dir(TestDataDirectory);
  string scriptfile = dir + base + ".txt";
  string pyfile = dir + base + ".py";
  string sedrtfile = dir + base + "_rt.py";
  char* py_gen = convertFile(scriptfile.c_str());
  if (py_gen==NULL) {
    cout << getLastSedmlScriptError() << endl << endl;
    fail_unless(false);
    return;
  }
  //cout << "SED-ML generated from " << base << ".txt" << endl << py_gen << endl;
  char* script_rt = getLastSedmlScript();

  char* script_gen = convertFile(pyfile.c_str());
  if (script_gen==NULL) {
    cout << getLastSedmlScriptError() << endl << endl;
    fail_unless(false);
    return;
  }
  //cout << "script-ML generated from " << base << ".py" << endl << script_gen << endl;


  char* script_rt_gen = convertFile(sedrtfile.c_str());
  char* sed_rt = getLastSEDML();

  fail_unless((string)script_rt == (string)script_gen);
  fail_unless((string)script_rt == (string)script_rt_gen);
  fail_unless((string)sed_rt     == (string)py_gen);
  //if (sed_rt != py_gen) {
  //  ofstream outfile2((dir + base + "_rt.py").c_str());
  //  outfile2.write(py_gen, ((string)py_gen).size());
  //  outfile2.close();
  //}

  free(py_gen);
  free(sed_rt);
  free(script_gen);
  free(script_rt);
  free(script_rt_gen);
}


END_C_DECLS
