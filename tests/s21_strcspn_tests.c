#include "s21_check.h"

START_TEST(strcspn_test_1) {
  char *str1 = "Hello  _World!$";
  char *str2 = "o!$_";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_2) {
  char *str1 = "Hello";
  char *str2 = "Hello";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_3) {
  char *str1 = "Hello";
  char *str2 = "Hello World!";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_4) {
  char *str1 = "Hello  _World!$";
  char *str2 = "o!$_H";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_5) {
  char *str1 = "Hello";
  char *str2 = " ";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_6) {
  char *str1 = " ";
  char *str2 = "Hello";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_7) {
  char *str1 = "Help!";
  char *str2 = " ";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s1 = suite_create("strcspn_suite");
  TCase *tc1_1 = tcase_create("strcspn_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strcspn_test_1);
  tcase_add_test(tc1_1, strcspn_test_2);
  tcase_add_test(tc1_1, strcspn_test_3);
  tcase_add_test(tc1_1, strcspn_test_4);
  tcase_add_test(tc1_1, strcspn_test_5);
  tcase_add_test(tc1_1, strcspn_test_6);
  tcase_add_test(tc1_1, strcspn_test_7);

  return s1;
}