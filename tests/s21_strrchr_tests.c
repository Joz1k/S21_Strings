#include "s21_check.h"

START_TEST(strrchr_1) {
  char str[] = "fififi-trixabelle";
  char c = 'i';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}

START_TEST(strrchr_2) {
  char str[] = "fififi-trixabelle";
  char c = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}

START_TEST(strrchr_3) {
  char str[] = "fififi-trixabelle";
  char c = 's';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}

START_TEST(strrchr_4) {
  char str[] = "";
  char c = 'e';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}

Suite *suite_strrchr(void) {
  Suite *s1 = suite_create("strrchr_suite");
  TCase *tc1 = tcase_create("strrchr_tcase");
  suite_add_tcase(s1, tc1);
  tcase_add_test(tc1, strrchr_1);
  tcase_add_test(tc1, strrchr_2);
  tcase_add_test(tc1, strrchr_3);
  tcase_add_test(tc1, strrchr_4);
  return s1;
}