#include "s21_check.h"

START_TEST(trim_test_1) {
  char *str1 = "Hello World!";
  char *str2 = "orl";
  char *result = s21_trim(str1, str2);
  ck_assert_str_eq(result, "He Wd!");
  free(result);
}
END_TEST

START_TEST(trim_test_2) {
  char *str1 = "hello world!";
  char *str2 = "dh";
  char *result = s21_trim(str1, str2);
  ck_assert_str_eq(result, "ello worl!");
  free(result);
}
END_TEST

START_TEST(trim_test_3) {
  char *str1 = "Much Ado About Nothing";
  char *str2 = "*\'sfwr";
  char *result = s21_trim(str1, str2);
  ck_assert_str_eq(result, "Much Ado About Nothing");
  free(result);
}
END_TEST

START_TEST(trim_test_4) {
  char *str1 = "                sdsafffffffffffffff";
  char *str2 = "f ";
  char *result = s21_trim(str1, str2);
  ck_assert_str_eq(result, "sdsa");
  free(result);
}
END_TEST

START_TEST(trim_test_5) {
  char *str1 = "dsds";
  char *str2 = "";
  char *result = s21_trim(str1, str2);
  ck_assert_str_eq(result, "dsds");
  free(result);
}
END_TEST

START_TEST(trim_test_6) {
  char *str1 = "";
  char *str2 = "Wsda";
  char *result = s21_trim(str1, str2);
  ck_assert_pstr_eq(result, "");
  free(result);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s1 = suite_create("trim_suite");
  TCase *tc1_1 = tcase_create("trim_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, trim_test_1);
  tcase_add_test(tc1_1, trim_test_2);
  tcase_add_test(tc1_1, trim_test_3);
  tcase_add_test(tc1_1, trim_test_4);
  tcase_add_test(tc1_1, trim_test_5);
  tcase_add_test(tc1_1, trim_test_6);
  /*
  tcase_add_test(tc1_1, trim_test_7);
  */

  return s1;
}