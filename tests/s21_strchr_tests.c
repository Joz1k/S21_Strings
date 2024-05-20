#include "s21_check.h"

START_TEST(strchr_1) {
  char str[] = "fififi-trixabelle";
  char c = 'a';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}

START_TEST(strchr_2) {
  char str[] = "fififi-trixabelle";
  char c = 's';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}

START_TEST(strchr_3) {
  char str[] = "";
  char c = 'a';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}

START_TEST(strchr_4) {
  char str[] = "fififi-trixabelle";
  char c = '\0';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}

Suite *suite_strchr(void) {
  Suite *s1 = suite_create("strchr_suite");
  TCase *tc1 = tcase_create("strchr_tcase");
  suite_add_tcase(s1, tc1);
  tcase_add_test(tc1, strchr_1);
  tcase_add_test(tc1, strchr_2);
  tcase_add_test(tc1, strchr_3);
  tcase_add_test(tc1, strchr_4);
  return s1;
}