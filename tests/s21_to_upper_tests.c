#include "s21_check.h"

START_TEST(to_upper_1) {
  char str[] = "good job";
  char expected[] = "GOOD JOB";
  char *res = s21_to_upper(str);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}

START_TEST(to_upper_2) {
  char str[] = "empty";
  char expected[] = "EMPTY";
  char *res = s21_to_upper(str);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}

START_TEST(to_upper_3) {
  char str[] = "1+1*1";
  char expected[] = "1+1*1";
  char *res = s21_to_upper(str);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}

START_TEST(to_upper_4) {
  char str[] = " ";
  char expected[] = " ";
  char *res = s21_to_upper(str);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}

Suite *suite_to_upper(void) {
  Suite *s1 = suite_create("to_upper_suite");
  TCase *tc1 = tcase_create("to_upper_tcase");
  suite_add_tcase(s1, tc1);
  tcase_add_test(tc1, to_upper_1);
  tcase_add_test(tc1, to_upper_2);
  tcase_add_test(tc1, to_upper_3);
  tcase_add_test(tc1, to_upper_4);
  return s1;
}