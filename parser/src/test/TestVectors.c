/**
 * \file    TestVectors.c
 * \brief   Test parsing vectors from SED-ML script.
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

START_TEST (test_equals_vector_num)
{
  compareStringTranslation("test = [5, 3, 2]", "eq_vec_num");
}
END_TEST

START_TEST (test_equals_vector_var)
{
  compareStringTranslation("test = [y, x, z]", "eq_vec_var");
}
END_TEST

START_TEST (test_equals_vector_mixed)
{
  compareStringTranslation("test = [y, 3, y+x, z**3/6]", "eq_vec_mixed");
}
END_TEST

START_TEST (test_equals_set_num)
{
  compareStringTranslation("test = {5, 3, 2}", "eq_set_num");
}
END_TEST

START_TEST (test_equals_set_var)
{
  compareStringTranslation("test = {y, x, z}", "eq_set_var");
}
END_TEST

START_TEST (test_equals_set_mixed)
{
  compareStringTranslation("test = {y, 3, y+x, z**3/6}", "eq_set_mixed");
}
END_TEST

START_TEST (test_equals_dict_num)
{
  compareStringTranslation("test = {a: 5, c: 3, hello: 2}", "eq_dict_num");
}
END_TEST

START_TEST (test_equals_dict_var)
{
  compareStringTranslation("test = {foo: y, bar: x, t43: z}", "eq_dict_var");
}
END_TEST

START_TEST (test_equals_dict_mixed)
{
  compareStringTranslation("test = {pl: y, h3vy: 3, p0: y+x, last: z**3/6}", "eq_dict_mixed");
}
END_TEST

START_TEST (test_equals_set_equals)
{
  compareStringTranslation("test = {pl == 3, x1 == x2}", "eq_set_equals");
}
END_TEST

START_TEST (test_equals_dict_equals)
{
  compareStringTranslation("test = {x: pl == 3, z: x1 == x2}", "eq_dict_equals");
}
END_TEST



Suite *
create_suite_Vectors (void)
{
  Suite *suite = suite_create("SED-ML Script Vectors and Sets");
  TCase *tcase = tcase_create("SED-ML Script Vectors and Sets");


  tcase_add_test( tcase, test_equals_vector_num);
  tcase_add_test( tcase, test_equals_vector_var);
  tcase_add_test( tcase, test_equals_vector_mixed);
  tcase_add_test( tcase, test_equals_set_num);
  tcase_add_test( tcase, test_equals_set_var);
  tcase_add_test( tcase, test_equals_set_mixed);
  tcase_add_test( tcase, test_equals_dict_num);
  tcase_add_test( tcase, test_equals_dict_var);
  tcase_add_test( tcase, test_equals_dict_mixed);
  tcase_add_test( tcase, test_equals_set_equals);
  tcase_add_test( tcase, test_equals_dict_equals);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS


