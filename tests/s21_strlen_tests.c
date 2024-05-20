#include "s21_check.h"

START_TEST(strlen_test_1) {
  char *str1 = "Hello  _World!$";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_test_2) {
  char *str1 = "Hello";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_test_3) {
  char *str1 = "  _ FD D A";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_test_4) {
  char *str1 = "Hello  _World!$";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_test_5) {
  char *str1 = " ";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_test_6) {
  char *str1 = "";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s1 = suite_create("strlen_suite");
  TCase *tc1_1 = tcase_create("strlen_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strlen_test_1);
  tcase_add_test(tc1_1, strlen_test_2);
  tcase_add_test(tc1_1, strlen_test_3);
  tcase_add_test(tc1_1, strlen_test_4);
  tcase_add_test(tc1_1, strlen_test_5);
  tcase_add_test(tc1_1, strlen_test_6);

  return s1;
}