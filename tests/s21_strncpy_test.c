#include "s21_check.h"

/*different sizes to copy*/
START_TEST(strncpy_test_1) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[100];
  s21_size_t n = sizeof(source) * 0;
  ck_assert_str_eq(s21_strncpy(destination, source, n),
                   strncpy(destination, source, n));
}
END_TEST

START_TEST(strncpy_test_2) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[100];
  s21_size_t n = sizeof(source);
  ck_assert_str_eq(s21_strncpy(destination, source, n),
                   strncpy(destination, source, n));
}
END_TEST

START_TEST(strncpy_test_3) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[100];
  s21_size_t n = sizeof(source) / 2;
  ck_assert_str_eq(s21_strncpy(destination, source, n),
                   strncpy(destination, source, n));

  /*different destination lengths*/
}
END_TEST

START_TEST(strncpy_test_4) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[15];
  s21_size_t n = sizeof(destination);
  ck_assert_str_eq(s21_strncpy(destination, source, n),
                   strncpy(destination, source, n));
}
END_TEST

START_TEST(strncpy_test_5) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[10];
  s21_size_t n = sizeof(destination);
  ck_assert_str_eq(s21_strncpy(destination, source, n),
                   strncpy(destination, source, n));

  /*source has less than n characters*/
}
END_TEST

START_TEST(strncpy_test_6) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[100];
  s21_size_t n = sizeof(destination);
  ck_assert_str_eq(s21_strncpy(destination, source, n),
                   strncpy(destination, source, n));

  /*copy empty string*/
}
END_TEST

START_TEST(strncpy_test_7) {
  char source[] = "";  // length = 0
  char destination[100];
  s21_size_t n = sizeof(destination);
  ck_assert_str_eq(s21_strncpy(destination, source, n),
                   strncpy(destination, source, n));
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s1 = suite_create("strncpy_suite");
  TCase *tc1_1 = tcase_create("strncpy_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strncpy_test_1);
  tcase_add_test(tc1_1, strncpy_test_2);
  tcase_add_test(tc1_1, strncpy_test_3);
  tcase_add_test(tc1_1, strncpy_test_4);
  tcase_add_test(tc1_1, strncpy_test_5);
  tcase_add_test(tc1_1, strncpy_test_6);
  tcase_add_test(tc1_1, strncpy_test_7);

  return s1;
}
