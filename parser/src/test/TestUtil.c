/**
 * \file    TestBasic.c
 * \brief   Test phraSEDML's basic constructs.
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
  string phrasedfile = dir + base + ".txt";
  string sedfile = dir + base + ".xml";
  char* sed_gen = convertFile(phrasedfile.c_str());
  if (sed_gen==NULL) {
    cout << getLastSedmlScriptError() << endl << endl;
    fail_unless(false);
    return;
  }
  //cout << "SED-ML generated from " << base << ".txt" << endl << sed_gen << endl;
  char* phrased_rt = getLastSedmlScript();

  char* phrased_gen = convertFile(sedfile.c_str());
  if (phrased_gen==NULL) {
    cout << getLastSedmlScriptError() << endl << endl;
    fail_unless(false);
    return;
  }
  //cout << "phraSED-ML generated from " << base << ".xml" << endl << phrased_gen << endl;
  char* sed_rt = getLastSEDML();

  fail_unless((string)phrased_rt == (string)phrased_gen);
  fail_unless((string)sed_rt     == (string)sed_gen);
  //if (sed_rt != sed_gen) {
  //  ofstream outfile((dir + base + ".xml").c_str());
  //  outfile.write(sed_gen, ((string)sed_gen).size());
  //  outfile.close();
  //}

  free(sed_gen);
  free(sed_rt);
  free(phrased_gen);
  free(phrased_rt);
}

void compareStringTranslation(const string& phrasedml, const string& sedml)
{
  char* sed_gen = convertString(phrasedml.c_str());
  cout << "Original:" << endl << phrasedml << endl;
  cout << "Translated:" << endl << sed_gen << endl;

  //LS DEBUG:  FOR NOW:
  if (g_registry.getError() == "") {
    //No errors!  Yay!
    cout << "No errors, but not parsed yet." << endl << endl;
    return;
  }

  if (sed_gen==NULL) {
    cout << getLastSedmlScriptError() << endl << endl;
    fail_unless(false);
    return;
  }
  char* phrased_rt = getLastSedmlScript();

  string dir(TestDataDirectory);
  string sedfile = dir + sedml;
  char* phrased_gen = convertFile(sedfile.c_str());
  if (phrased_gen==NULL) {
    cout << getLastSedmlScriptError() << endl << endl;
    fail_unless(false);
    return;
  }
  char* sed_rt = getLastSEDML();

  fail_unless((string)phrased_rt == (string)phrased_gen);
  fail_unless((string)sed_rt     == (string)sed_gen);

  free(sed_gen);
  free(sed_rt);
  free(phrased_gen);
  free(phrased_rt);
}

void compareStringAndFileTranslation(const string& phrasedml, const string& base)
{
  compareStringTranslation(phrasedml, base+".xml");
  compareFileTranslation(base);
}

void compareOriginalXMLTranslations(const string& base)
{
  string dir(TestDataDirectory);
  string phrasedfile = dir + base + ".txt";
  string sedfile = dir + base + ".xml";
  string sedrtfile = dir + base + "_rt.xml";
  char* sed_gen = convertFile(phrasedfile.c_str());
  if (sed_gen==NULL) {
    cout << getLastSedmlScriptError() << endl << endl;
    fail_unless(false);
    return;
  }
  //cout << "SED-ML generated from " << base << ".txt" << endl << sed_gen << endl;
  char* phrased_rt = getLastSedmlScript();

  char* phrased_gen = convertFile(sedfile.c_str());
  if (phrased_gen==NULL) {
    cout << getLastSedmlScriptError() << endl << endl;
    fail_unless(false);
    return;
  }
  //cout << "phraSED-ML generated from " << base << ".xml" << endl << phrased_gen << endl;


  char* phrased_rt_gen = convertFile(sedrtfile.c_str());
  char* sed_rt = getLastSEDML();

  fail_unless((string)phrased_rt == (string)phrased_gen);
  fail_unless((string)phrased_rt == (string)phrased_rt_gen);
  fail_unless((string)sed_rt     == (string)sed_gen);
  //if (sed_rt != sed_gen) {
  //  ofstream outfile2((dir + base + "_rt.xml").c_str());
  //  outfile2.write(sed_gen, ((string)sed_gen).size());
  //  outfile2.close();
  //}

  free(sed_gen);
  free(sed_rt);
  free(phrased_gen);
  free(phrased_rt);
  free(phrased_rt_gen);
}


END_C_DECLS
