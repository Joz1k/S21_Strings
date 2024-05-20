#include "s21_check.h"

START_TEST(to_lower_1) {
  char str[] = "GOOD JOB";
  char expected[] = "good job";
  char *res = s21_to_lower(str);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}

START_TEST(to_lower_2) {
  char str[] = "1234567890Z";
  char expected[] = "1234567890z";
  char *res = s21_to_lower(str);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}

START_TEST(to_lower_3) {
  char str[] = "Lower";
  char expected[] = "lower";
  char *res = s21_to_lower(str);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}

START_TEST(to_lower_4) {
  char str[] = "";
  char expected[] = "";
  char *res = s21_to_lower(str);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}

Suite *suite_to_lower(void) {
  Suite *s1 = suite_create("to_lower_suite");
  TCase *tc1 = tcase_create("to_lower_tcase");
  suite_add_tcase(s1, tc1);
  tcase_add_test(tc1, to_lower_1);
  tcase_add_test(tc1, to_lower_2);
  tcase_add_test(tc1, to_lower_3);
  tcase_add_test(tc1, to_lower_4);
  return s1;
}