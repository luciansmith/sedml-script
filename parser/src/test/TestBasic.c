/**
 * \file    TestBasic.c
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

START_TEST (test_equals_num)
{
  compareStringTranslation("test = 5", "");
}
END_TEST

START_TEST (test_equals_val)
{
  compareStringTranslation("test = x", "");
}
END_TEST

START_TEST (test_equals_subval)
{
  compareStringTranslation("test = x.y", "");
}
END_TEST

START_TEST (test_equals_formula)
{
  compareStringTranslation("test = x + 4/20", "");
}
END_TEST

START_TEST (test_block_if)
{
  compareStringTranslation("if x:\n  y=4\n  z=3", "");
}
END_TEST

START_TEST (test_block_if_end_rets)
{
  compareStringTranslation("if x:\n  y=4\n  z=3\n\n", "");
}
END_TEST

START_TEST (test_block_extra_rets)
{
  compareStringTranslation("if x:\n  y=4\n\n\n  z=3", "");
}
END_TEST

START_TEST (test_block_then_equals)
{
  compareStringTranslation("if x:\n  y=4\n  z=3\n\nq=n", "");
}
END_TEST

START_TEST (test_nested_blocks)
{
  compareStringTranslation("if x:\n  if y:\n    q=3", "");
}
END_TEST

START_TEST (test_nested_blocks_then_equals)
{
  compareStringTranslation("if x:\n  if y:\n    q=3\np=y", "");
}
END_TEST

START_TEST (test_nested_blocks_staggered_deindent1)
{
  compareStringTranslation("if x:\n  if y:\n    q=3\n  p=y\n  d=z", "");
}
END_TEST

START_TEST (test_nested_blocks_staggered_deindent2)
{
  compareStringTranslation("if x:\n  if y:\n    q=3\n  p=y\n  d=z\n  u=l\ng=3", "");
}
END_TEST


Suite *
create_suite_Basic (void)
{
  Suite *suite = suite_create("SED-ML Script Basic");
  TCase *tcase = tcase_create("SED-ML Script Basic");


  tcase_add_test( tcase, test_equals_num);
  tcase_add_test( tcase, test_equals_val);
  tcase_add_test( tcase, test_equals_subval);
  tcase_add_test( tcase, test_equals_formula);
  tcase_add_test( tcase, test_block_if);
  tcase_add_test( tcase, test_block_if_end_rets);
  tcase_add_test( tcase, test_block_extra_rets);
  tcase_add_test( tcase, test_block_then_equals);

  tcase_add_test( tcase, test_nested_blocks);
  tcase_add_test( tcase, test_nested_blocks_then_equals);
  tcase_add_test( tcase, test_nested_blocks_staggered_deindent1);
  tcase_add_test( tcase, test_nested_blocks_staggered_deindent2);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS


