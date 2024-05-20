#include "s21_check.h"

START_TEST(memchr_1) {
  char str[] = "fififi-trixabelle";
  char c = 'a';
  s21_size_t n = sizeof(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

START_TEST(memchr_2) {
  char str[] = "fififi-trixabelle";
  char c = 'a';
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

START_TEST(memchr_3) {
  char str[] = "fififi-trixabelle";
  char c = 'f';
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

START_TEST(memchr_4) {
  char str[] = "fififi-trixabelle";
  char c = 'i';
  s21_size_t n = 0;
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

START_TEST(memchr_5) {
  char str[] = "fififi-trixabelle";
  char c = 's';
  s21_size_t n = sizeof(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

START_TEST(memchr_6) {
  char str[] = "";
  char c = '\0';
  s21_size_t n = sizeof(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

Suite *suite_memchr(void) {
  Suite *s1 = suite_create("memchr_suite");
  TCase *tc1 = tcase_create("memchr_tcase");
  suite_add_tcase(s1, tc1);
  tcase_add_test(tc1, memchr_1);
  tcase_add_test(tc1, memchr_2);
  tcase_add_test(tc1, memchr_3);
  tcase_add_test(tc1, memchr_4);
  tcase_add_test(tc1, memchr_5);
  tcase_add_test(tc1, memchr_6);
  return s1;
}