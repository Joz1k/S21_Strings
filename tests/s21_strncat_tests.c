#include "s21_check.h"

START_TEST(strncat_test_1) {
  char str_1[256] = "Hello, world!";
  char str_2[256] = "Hello, world!";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncat(str_1, str_2, n), strncat(str_1, str_2, n));
}
END_TEST

START_TEST(strncat_test_2) {
  char str_1[256] = "Hello, world!";
  char str_2[256] = "Hello, world!";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncat(str_1, str_2, n), strncat(str_1, str_2, n));
}
END_TEST

START_TEST(strncat_test_3) {
  char str_1[256] = "Hello, world!";
  char str_2[256] = "Hello, world!";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncat(str_1, str_2, n), strncat(str_1, str_2, n));
}
END_TEST

START_TEST(strncat_test_4) {
  char str_1[256] = "Hello";
  char str_2[256] = "Hello, world!";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncat(str_1, str_2, n), strncat(str_1, str_2, n));
}
END_TEST

START_TEST(strncat_test_5) {
  char str_1[256] = "Hello\0, world!";
  char str_2[256] = "Hel\0lo";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncat(str_1, str_2, n), strncat(str_1, str_2, n));
}
END_TEST

START_TEST(strncat_test_6) {
  char str_1[256] = "";
  char str_2[256] = "";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncat(str_1, str_2, n), strncat(str_1, str_2, n));
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s1 = suite_create("strncat_suite");
  TCase *tc1_1 = tcase_create("strncat_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strncat_test_1);
  tcase_add_test(tc1_1, strncat_test_2);
  tcase_add_test(tc1_1, strncat_test_3);
  tcase_add_test(tc1_1, strncat_test_4);
  tcase_add_test(tc1_1, strncat_test_5);
  tcase_add_test(tc1_1, strncat_test_6);

  return s1;
}
