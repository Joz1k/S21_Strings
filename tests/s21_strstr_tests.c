#include "s21_check.h"

START_TEST(strstr_1) {
  char str[] = "fififi-trixabelle";
  char str2[] = "fifi-trixabelle";
  ck_assert_pstr_eq(s21_strstr(str, str2), strstr(str, str2));
}

START_TEST(strstr_2) {
  char str[] = "fififi-trixabelle";
  char str2[] = "ses";
  ck_assert_pstr_eq(s21_strstr(str, str2), strstr(str, str2));
}

START_TEST(strstr_3) {
  char str[] = "fififi-trixabelle";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strstr(str, str2), strstr(str, str2));
}

START_TEST(strstr_4) {
  char str[] = "";
  char str2[] = "fififasdas";
  ck_assert_pstr_eq(s21_strstr(str, str2), strstr(str, str2));
}

START_TEST(strstr_5) {
  char str[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strstr(str, str2), strstr(str, str2));
}

START_TEST(strstr_6) {
  char str[] = "fififi-trixabelle";
  char str2[] = "\0";
  ck_assert_pstr_eq(s21_strstr(str, str2), strstr(str, str2));
}

Suite *suite_strstr(void) {
  Suite *s1 = suite_create("strstr_suite");
  TCase *tc1 = tcase_create("strstr_tcase");
  suite_add_tcase(s1, tc1);
  tcase_add_test(tc1, strstr_1);
  tcase_add_test(tc1, strstr_2);
  tcase_add_test(tc1, strstr_3);
  tcase_add_test(tc1, strstr_4);
  tcase_add_test(tc1, strstr_5);
  tcase_add_test(tc1, strstr_6);
  return s1;
}