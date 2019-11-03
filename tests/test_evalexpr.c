/*
** EPITECH PROJECT, 2019
** eval_expr_test
** File description:
** Test Eval_expr
*/

#include <stdio.h>
#include <criterion/criterion.h>

char *eval_expr(char const *s, char *base, char *);

char *modifstr(char *str, char *, char *);

int error_test(char *str, char *base, char *spec);

Test(evalexpr, 4_plus_4)
{
    cr_assert_str_eq(eval_expr(modifstr("4+4", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "8");
}

Test(evalexpr, 5_less_3)
{
    cr_assert_str_eq(eval_expr(modifstr("5-3", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "2");
}

Test(evalexpr, minus_5_less_3)
{
    cr_assert_str_eq(eval_expr(modifstr("-5-3", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "-8");
}

Test(evalexpr, minus_5_plus_3)
{
    cr_assert_str_eq(eval_expr(modifstr("-5+3", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "-2");
}

Test(evalexpr, minus_500_plus_3000)
{
    cr_assert_str_eq(eval_expr(modifstr("-500+3000", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "2500");
}

Test(evalexpr, 5_mult_5)
{
    cr_assert_str_eq(eval_expr(modifstr("5*5", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "25");
}

Test(evalexpr, less_less_5)
{
    cr_assert_str_eq(eval_expr(modifstr("-(-5)", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "5");
}

Test(evalexpr, 3_mult_4_div_2_mod_4)
{
    cr_assert_str_eq(eval_expr(modifstr("3*4/2%4", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "2");
}

Test(evalexpr, multiple_op_one)
{
    cr_assert_str_eq(eval_expr(modifstr("5+(2*-1*(-3*-(-1+4))+9*-2)",
                                        "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "-31");
}

Test(evalexpr, multiple_op_two)
{
    cr_assert_str_eq(eval_expr(modifstr("5+(2*-1*(-3*-(-1+4))+9*-2)-2+2+2",
                                        "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "-29");
}

Test(evalexpr, 2_div_4)
{
    cr_assert_str_eq(eval_expr(modifstr("2/4", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "0");
}
Test(evalexpr, minus_2_div_4)
{
    cr_assert_str_eq(eval_expr(modifstr("-2/4", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "0");
}

Test(evalexpr, minus_2_div_minus_4)
{
    cr_assert_str_eq(eval_expr(modifstr("-2/-4", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "0");
}

Test(evalexpr, 2_div_minus_4)
{
    cr_assert_str_eq(eval_expr(modifstr("2/-4", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "0");
}

Test(evalexpr, 2_mod_4)
{
    cr_assert_str_eq(eval_expr(modifstr("2%4", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "2");
}
Test(evalexpr, minus_2_mod_4)
{
    cr_assert_str_eq(eval_expr(modifstr("-2%4", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "-2");
}

Test(evalexpr, minus_2_mod_minus_4)
{
    cr_assert_str_eq(eval_expr(modifstr("-2%-4", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "-2");
}

Test(evalexpr, 2_div_mod_4)
{
    cr_assert_str_eq(eval_expr(modifstr("2%-4", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "2");
}

Test(error_test, error_none)
{
    cr_assert_eq(error_test("1+1\n", "0123456789", "()+-*/%"), 0);
}

Test(error_test, error_void)
{
    cr_assert_eq(error_test("", "0123456789", "()+-*/%"), 1);
}

Test(error_test, error_par)
{
    cr_assert_eq(error_test("(1+1", "0123456789", "()+-*/%"), 1);
}


Test(error_test, error_char)
{
    cr_assert_eq(error_test("a1+1", "0123456789", "()+-*/%"), 1);
}


Test(error_test, error_spec_1)
{
    cr_assert_eq(error_test("1+1", "0123456789", "()-*/%"), 1);
}

Test(error_test, error_spec_2)
{
    cr_assert_eq(error_test("1+1", "0123456789", "()+-*/%$"), 1);
}

Test(error_test, error_spec_3)
{
    cr_assert_eq(error_test("1+1", "0123456789", "()+-*/+"), 1);
}

Test(error_test, error_base_1)
{
    cr_assert_eq(error_test("1+1", "0123456789", "()9-*/%"), 1);
}

Test(error_test, error_base_2)
{
    cr_assert_eq(error_test("1+1", "012345678+", "()+-*/%"), 1);
}

Test(error_test, error_base_3)
{
    cr_assert_eq(error_test("1+1", "0123456799", "()+-*/%"), 1);
}

Test(evalexpr, multiple_op_three)
{
    cr_assert_str_eq(eval_expr(modifstr("5+(2*-1*(-3*-(-1+4)))+9*-2+2%2+2/2-1",
                                        "0123456789", "()+-*/%"), "0123456789",
                                        "()+-*/%"), "-31");
}

Test(evalexpr, multiple_five_five)
{
    cr_assert_str_eq(eval_expr(modifstr("5*5*5", "0123456789", "()+-*/%"),
                                        "0123456789", "()+-*/%"), "125");
}
