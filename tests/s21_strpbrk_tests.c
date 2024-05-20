#include "s21_check.h"

START_TEST(strpbrk_test_1) {
  char *str1 = "Hello  _World!$";
  char *str2 = "o";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_2) {
  char *str1 = "Hello";
  char *str2 = "o";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_3) {
  char *str1 = "  _ FD D A";
  char *str2 = "F";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_4) {
  char *str1 = "Hello  _World!$";
  char *str2 = "_";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_5) {
  char *str1 = "Hello  _World!$";
  char *str2 = "H";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_6) {
  char *str1 = "Hello  _World!$";
  char *str2 = "SD";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_7) {
  char *str1 = "Hello  _World!$";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_8) {
  char *str1 = "";
  char *str2 = "SDSADA";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_9) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s1 = suite_create("strpbrk_suite");
  TCase *tc1_1 = tcase_create("strpbrk_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strpbrk_test_1);
  tcase_add_test(tc1_1, strpbrk_test_2);
  tcase_add_test(tc1_1, strpbrk_test_3);
  tcase_add_test(tc1_1, strpbrk_test_4);
  tcase_add_test(tc1_1, strpbrk_test_5);
  tcase_add_test(tc1_1, strpbrk_test_6);
  tcase_add_test(tc1_1, strpbrk_test_7);
  tcase_add_test(tc1_1, strpbrk_test_8);
  tcase_add_test(tc1_1, strpbrk_test_9);

  return s1;
}