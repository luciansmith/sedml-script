/**
 * \file    TestExamples.c
 * \brief   Test parsing Basic in phraSEDML's constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "sedml-script-api.h"
#include "TestUtil.h"

#include <string>
#include <check.h>
#include <iostream>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;
SEDMLSCRIPT_CPP_NAMESPACE_USE

START_TEST (test_example1)
{
  compareFileTranslation("example1");
}
END_TEST


START_TEST (test_example2)
{
  compareFileTranslation("example2");
}
END_TEST


START_TEST (test_example3)
{
  compareFileTranslation("example3");
}
END_TEST


Suite *
create_suite_Examples (void)
{
  Suite *suite = suite_create("SED-ML Script Examples");
  TCase *tcase = tcase_create("SED-ML Script Examples");


  tcase_add_test( tcase, test_example1);
  tcase_add_test( tcase, test_example2);
  tcase_add_test( tcase, test_example3);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS


