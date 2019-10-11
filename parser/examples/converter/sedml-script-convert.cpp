/**
 * @file    generateTestsFrom.cpp
 * @brief   Takes a test case model and generates the translated versions of the model plus the .m file.
 * @author  Lucian Smith
 * 
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <sstream>

#include "src\sedml-script-api.h"

using namespace std;

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << endl << "Usage: sedml-script-convert [filename]" << endl << endl;
    return 1;
  }

  char* translated = sedmlscript::convertFile(argv[1]);
  if (translated==NULL) {
    cerr << endl << "Unable to translate " << argv[1] << ": " << sedmlscript::getLastSedmlScriptError() << endl << endl;
    return 1;
  }
  cout << translated;
  return 0;
}
