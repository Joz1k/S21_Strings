#include "s21_check.h"

START_TEST(strncmp_test_1) {
  char str_1[256] = "Hello, world!";
  char str_2[256] = "Hello, world!";
  s21_size_t n = 20;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(strncmp_test_2) {
  char str_1[256] = "Hello, world!";
  char str_2[256] = "Hello, world!";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(strncmp_test_3) {
  char str_1[256] = "Hello, world!";
  char str_2[256] = "Hello, world!";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(strncmp_test_4) {
  char str_1[256] = "Hello";
  char str_2[256] = "Hello, world!";
  s21_size_t n = 20;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(strncmp_test_5) {
  char str_1[256] = "Hello, world!";
  char str_2[256] = "Hello";
  s21_size_t n = 20;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(strncmp_test_6) {
  char str_1[256] = "";
  char str_2[256] = "Hello, world!";
  s21_size_t n = 20;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(strncmp_test_7) {
  char str_1[256] = "Hello, world!";
  char str_2[256] = "";
  s21_size_t n = 20;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(strncmp_test_8) {
  char str_1[256] = "";
  char str_2[256] = "";
  s21_size_t n = 20;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(strncmp_test_9) {
  char str_1[256] = "\0asdad\0";
  char str_2[256] = "\0dddd\0";
  s21_size_t n = 20;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(strncmp_test_10) {
  char str_1[256] = "";
  char str_2[256] = "";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s1 = suite_create("strncmp_suite");
  TCase *tc1_1 = tcase_create("strncmp_testcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strncmp_test_1);
  tcase_add_test(tc1_1, strncmp_test_2);
  tcase_add_test(tc1_1, strncmp_test_3);
  tcase_add_test(tc1_1, strncmp_test_4);
  tcase_add_test(tc1_1, strncmp_test_5);
  tcase_add_test(tc1_1, strncmp_test_6);
  tcase_add_test(tc1_1, strncmp_test_7);
  tcase_add_test(tc1_1, strncmp_test_8);
  tcase_add_test(tc1_1, strncmp_test_9);
  tcase_add_test(tc1_1, strncmp_test_10);

  return s1;
}
