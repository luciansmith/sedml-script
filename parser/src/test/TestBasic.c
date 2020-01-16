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
  compareStringTranslation("test = 5", "eq_num");
}
END_TEST

START_TEST (test_equals_val)
{
  compareStringTranslation("test = x", "eq_val");
}
END_TEST

START_TEST (test_equals_subval)
{
  compareStringTranslation("test = x.y", "eq_subval");
}
END_TEST

START_TEST (test_equals_formula)
{
  compareStringTranslation("test = x + 4/20", "eq_formula");
}
END_TEST

START_TEST (test_block_if)
{
  compareStringTranslation("if x:\n  y=4\n  z=3", "block_if");
}
END_TEST

START_TEST (test_block_if_end_rets)
{
  compareStringTranslation("if x:\n  y=4\n  z=3\n\n", "if_end_rets");
}
END_TEST

START_TEST (test_block_extra_rets)
{
  compareStringTranslation("if x:\n  y=4\n\n\n  z=3", "if_extra_rets");
}
END_TEST

START_TEST (test_block_then_equals)
{
  compareStringTranslation("if x:\n  y=4\n  z=3\n\nq=n", "if_then_eq");
}
END_TEST

START_TEST (test_nested_blocks)
{
  compareStringTranslation("if x:\n  if y:\n    q=3", "nested_blocks");
}
END_TEST

START_TEST (test_nested_blocks_then_equals)
{
  compareStringTranslation("if x:\n  if y:\n    q=3\np=y", "nested_then_eq");
}
END_TEST

START_TEST (test_nested_blocks_staggered_deindent1)
{
  compareStringTranslation("if x:\n  if y:\n    q=3\n  p=y\n  d=z", "nested_staggered_deindent1");
}
END_TEST

START_TEST (test_nested_blocks_staggered_deindent2)
{
  compareStringTranslation("if x:\n  if y:\n    q=3\n  p=y\n  d=z\n  u=l\ng=3", "nested_staggered_deindent2");
}
END_TEST

START_TEST (test_subscript_assignment_num)
{
  compareStringTranslation("x[3] = 2", "subscript_assignment_num");
}
END_TEST

START_TEST (test_subscript_assignment_var)
{
  compareStringTranslation("x[y] = z", "subscript_assignment_var");
}
END_TEST

START_TEST (test_subscript_assignment_varsub_if)
{
  compareStringTranslation("if True:\n  x[y] = z", "subscript_assignment_varsub_if");
}
END_TEST

START_TEST (test_subscript_assignment_varsub_for)
{
  compareStringTranslation("for foo in bar:\n  bar[foo] = 3", "subscript_assignment_varsub_for");
}
END_TEST

START_TEST (test_execute_onearg)
{
  compareStringTranslation("bar(foo)", "execute_onearg");
}
END_TEST

START_TEST (test_execute_subvar)
{
  compareStringTranslation("bar[x](foo)", "execute_subvar");
}
END_TEST

START_TEST (test_select_subvar)
{
  compareStringTranslation("bar[x].foo()", "select_subvar");
}
END_TEST

START_TEST (test_func_subvar)
{
  compareStringTranslation("bar(x).foo()", "func_subvar");
}
END_TEST

START_TEST (test_func_select_subvar)
{
  compareStringTranslation("bar(x)[foo]()", "func_select_subvar");
}
END_TEST

START_TEST (test_multi_func_subvar)
{
  compareStringTranslation("bar[foo](1, 3, 5)", "multi_func_subvar");
}
END_TEST


Suite *
create_suite_Basic (void)
{
  Suite *suite = suite_create("SED-ML Script Basic");
  TCase *tcase = tcase_create("SED-ML Script Basic");


  tcase_add_test( tcase, test_execute_subvar);
  tcase_add_test( tcase, test_select_subvar);
  tcase_add_test( tcase, test_func_subvar);
  tcase_add_test( tcase, test_func_select_subvar);
  tcase_add_test( tcase, test_multi_func_subvar);

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

  tcase_add_test( tcase, test_subscript_assignment_num);
  tcase_add_test( tcase, test_subscript_assignment_var);
  tcase_add_test( tcase, test_subscript_assignment_varsub_if);
  tcase_add_test( tcase, test_subscript_assignment_varsub_for);

  tcase_add_test( tcase, test_execute_onearg);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS


