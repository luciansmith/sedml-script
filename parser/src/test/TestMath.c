/**
 * \file    TestMath.c
 * \brief   Test parsing math construccts in SED-ML Script.
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

START_TEST (test_math_abs)
{
  compareStringTranslation("abs(0.5)", "math_abs");
}
END_TEST

START_TEST (test_math_arccos)
{
  compareStringTranslation("arccos(0.5)", "math_arccos");
}
END_TEST

START_TEST (test_math_arccosh)
{
  compareStringTranslation("arccosh(1.5)", "math_arccosh");
}
END_TEST

START_TEST (test_math_arccot)
{
  compareStringTranslation("arccot(0.5)", "math_arccot");
}
END_TEST

START_TEST (test_math_arccoth)
{
  compareStringTranslation("arccoth(0.5)", "math_arccoth");
}
END_TEST

START_TEST (test_math_arccsc)
{
  compareStringTranslation("arccsc(0.5)", "math_arccsc");
}
END_TEST

START_TEST (test_math_arcsec)
{
  compareStringTranslation("arcsec(0.5)", "math_arcsec");
}
END_TEST

START_TEST (test_math_arcsech)
{
  compareStringTranslation("arcsech(0.5)", "math_arcsech");
}
END_TEST

START_TEST (test_math_arcsin)
{
  compareStringTranslation("arcsin(0.5)", "math_arcsin");
}
END_TEST

START_TEST (test_math_arcsinh)
{
  compareStringTranslation("arcsinh(0.5)", "math_arcsinh");
}
END_TEST

START_TEST (test_math_arctan)
{
  compareStringTranslation("arctan(0.5)", "math_arctan");
}
END_TEST

START_TEST (test_math_arctanh)
{
  compareStringTranslation("arctanh(0.5)", "math_arctanh");
}
END_TEST

START_TEST (test_math_ceiling)
{
  compareStringTranslation("ceiling(0.5)", "math_ceiling");
}
END_TEST

START_TEST (test_math_cos)
{
  compareStringTranslation("cos(0.5)", "math_cos");
}
END_TEST

START_TEST (test_math_cosh)
{
  compareStringTranslation("cosh(0.5)", "math_cosh");
}
END_TEST

START_TEST (test_math_cot)
{
  compareStringTranslation("cot(0.5)", "math_cot");
}
END_TEST

START_TEST (test_math_coth)
{
  compareStringTranslation("coth(0.5)", "math_coth");
}
END_TEST

START_TEST (test_math_csc)
{
  compareStringTranslation("csc(0.5)", "math_csc");
}
END_TEST

START_TEST (test_math_csch)
{
  compareStringTranslation("csch(0.5)", "math_csch");
}
END_TEST

START_TEST (test_math_exp)
{
  compareStringTranslation("exp(0.5)", "math_exp");
}
END_TEST

START_TEST (test_math_factorial)
{
  compareStringTranslation("factorial(5)", "math_factorial");
}
END_TEST

START_TEST (test_math_floor)
{
  compareStringTranslation("floor(0.5)", "math_floor");
}
END_TEST

START_TEST (test_math_ln)
{
  compareStringTranslation("ln(0.5)", "math_ln");
}
END_TEST

START_TEST (test_math_log)
{
  compareStringTranslation("log(10, 3)", "math_log");
}
END_TEST

START_TEST (test_math_log10)
{
  compareStringTranslation("log10(0.5)", "math_log10");
}
END_TEST

START_TEST (test_math_power)
{
  compareStringTranslation("power(x, 3)", "math_power");
}
END_TEST

START_TEST (test_math_root)
{
  compareStringTranslation("root(3, 27)", "math_root");
}
END_TEST

START_TEST (test_math_root2)
{
  compareStringTranslation("root(2, 25)", "math_root2");
}
END_TEST

START_TEST (test_math_sqrt)
{
  compareStringTranslation("sqrt(16)", "math_sqrt");
}
END_TEST

START_TEST (test_math_sec)
{
  compareStringTranslation("sec(0.5)", "math_sec");
}
END_TEST

START_TEST (test_math_sech)
{
  compareStringTranslation("sech(0.5)", "math_sech");
}
END_TEST

START_TEST (test_math_sin)
{
  compareStringTranslation("sin(0.5)", "math_sin");
}
END_TEST

START_TEST (test_math_sinh)
{
  compareStringTranslation("sinh(0.5)", "math_sinh");
}
END_TEST

START_TEST (test_math_tan)
{
  compareStringTranslation("tan(0.5)", "math_tan");
}
END_TEST

START_TEST (test_math_tanh)
{
  compareStringTranslation("tanh(0.5)", "math_tanh");
}
END_TEST

START_TEST (test_math_exponentiale)
{
  compareStringTranslation("exponentiale", "math_exponentiale");
}
END_TEST

START_TEST (test_math_false)
{
  compareStringTranslation("False", "math_false");
}
END_TEST

START_TEST (test_math_pi)
{
  compareStringTranslation("pi", "math_pi");
}
END_TEST

START_TEST (test_math_true)
{
  compareStringTranslation("True", "math_true");
}
END_TEST

START_TEST (test_math_avogadro)
{
  compareStringTranslation("avogadro", "math_avogadro");
}
END_TEST

START_TEST (test_math_piecewise)
{
  compareStringTranslation("x = 2\ny = piecewise(x, x==3, 5)", "math_piecewise");
}
END_TEST


START_TEST(test_math_all)
{
  compareStringTranslation("abs(0.5)\n"
    "arccos(0.5)\n"
    "arccosh(1.5)\n"
    "arccot(0.5)\n"
    "arccoth(0.5)\n"
    "arccsc(0.5)\n"
    "arcsec(0.5)\n"
    "arcsech(0.5)\n"
    "arcsin(0.5)\n"
    "arcsinh(0.5)\n"
    "arctan(0.5)\n"
    "arctanh(0.5)\n"
    "ceiling(0.5)\n"
    "cos(0.5)\n"
    "cosh(0.5)\n"
    "cot(0.5)\n"
    "coth(0.5)\n"
    "csc(0.5)\n"
    "csch(0.5)\n"
    "exp(0.5)\n"
    "factorial(5)\n"
    "floor(0.5)\n"
    "ln(0.5)\n"
    "log(10, 3)\n"
    "log10(0.5)\n"
    "power(x, 3)\n"
    "root(3, 27)\n"
    "root(2, 25)\n"
    "sqrt(16)\n"
    "sec(0.5)\n"
    "sech(0.5)\n"
    "sin(0.5)\n"
    "sinh(0.5)\n"
    "tan(0.5)\n"
    "tanh(0.5)\n"
    "exponentiale\n"
    "False\n"
    "pi\n"
    "True\n"
    "avogadro\n"
    "x = 2\ny = piecewise(x, x==3,5)\n", "math_all");
}
END_TEST



Suite *
create_suite_Math(void)
{
  Suite *suite = suite_create("SED-ML Script Math");
  TCase *tcase = tcase_create("SED-ML Script Math");

  tcase_add_test(tcase, test_math_abs);
  tcase_add_test(tcase, test_math_arccos);
  tcase_add_test(tcase, test_math_arccosh);
  tcase_add_test(tcase, test_math_arccot);
  tcase_add_test(tcase, test_math_arccoth);
  tcase_add_test(tcase, test_math_arccsc);
  tcase_add_test(tcase, test_math_arcsec);
  tcase_add_test(tcase, test_math_arcsech);
  tcase_add_test(tcase, test_math_arcsin);
  tcase_add_test(tcase, test_math_arcsinh);
  tcase_add_test(tcase, test_math_arctan);
  tcase_add_test(tcase, test_math_arctanh);
  tcase_add_test(tcase, test_math_ceiling);
  tcase_add_test(tcase, test_math_cos);
  tcase_add_test(tcase, test_math_cosh);
  tcase_add_test(tcase, test_math_cot);
  tcase_add_test(tcase, test_math_coth);
  tcase_add_test(tcase, test_math_csc);
  tcase_add_test(tcase, test_math_csch);
  tcase_add_test(tcase, test_math_exp);
  tcase_add_test(tcase, test_math_factorial);
  tcase_add_test(tcase, test_math_floor);
  tcase_add_test(tcase, test_math_ln);
  tcase_add_test(tcase, test_math_log);
  tcase_add_test(tcase, test_math_log10);
  tcase_add_test(tcase, test_math_power);
  tcase_add_test(tcase, test_math_root);
  tcase_add_test(tcase, test_math_root2);
  tcase_add_test(tcase, test_math_sqrt);
  tcase_add_test(tcase, test_math_sec);
  tcase_add_test(tcase, test_math_sech);
  tcase_add_test(tcase, test_math_sin);
  tcase_add_test(tcase, test_math_sinh);
  tcase_add_test(tcase, test_math_tan);
  tcase_add_test(tcase, test_math_tanh);
  tcase_add_test(tcase, test_math_exponentiale);
  tcase_add_test(tcase, test_math_false);
  tcase_add_test(tcase, test_math_pi);
  tcase_add_test(tcase, test_math_true);
  tcase_add_test(tcase, test_math_avogadro);
  tcase_add_test(tcase, test_math_piecewise);

  tcase_add_test(tcase, test_math_all);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS


