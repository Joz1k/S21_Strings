#include "s21_check.h"

START_TEST(insert_test_1) {
  char *str1 = "Hello  _World!";
  char *str2 = "Hel";
  char *result = s21_insert(str1, str2, 4);
  ck_assert_str_eq(result, "HellHelo  _World!");
  free(result);
}
END_TEST

START_TEST(insert_test_2) {
  char *str1 = "Hello";
  char *str2 = " World!";
  char *result = s21_insert(str1, str2, 5);
  ck_assert_str_eq(result, "Hello World!");
  free(result);
}
END_TEST

START_TEST(insert_test_3) {
  char *str1 = "FD";
  char *str2 = "F";
  char *result = s21_insert(str1, str2, 2);
  ck_assert_str_eq(result, "FDF");
  free(result);
}
END_TEST

START_TEST(insert_test_4) {
  char *str1 = " ";
  char *str2 = "Help!";
  char *result = s21_insert(str1, str2, 1);
  ck_assert_str_eq(result, " Help!");
  free(result);
}
END_TEST

START_TEST(insert_test_5) {
  char *str1 = "Hello";
  char *str2 = "He";
  char *result = s21_insert(str1, str2, 0);
  ck_assert_str_eq(result, "HeHello");
  free(result);
}
END_TEST

START_TEST(insert_test_6) {
  char *str1 = "He    ";
  char *str2 = "Wo";
  char *result = s21_insert(str1, str2, 6);
  ck_assert_pstr_eq(result, "He    Wo");
  free(result);
}
END_TEST

START_TEST(insert_test_7) {
  char *str1 = "Puskin";
  char *str2 = "h";
  char *result = s21_insert(str1, str2, 3);
  ck_assert_pstr_eq(result, "Pushkin");
  free(result);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s1 = suite_create("insert_suite");
  TCase *tc1_1 = tcase_create("insert_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, insert_test_1);
  tcase_add_test(tc1_1, insert_test_2);
  tcase_add_test(tc1_1, insert_test_3);
  tcase_add_test(tc1_1, insert_test_4);
  tcase_add_test(tc1_1, insert_test_5);
  tcase_add_test(tc1_1, insert_test_6);
  tcase_add_test(tc1_1, insert_test_7);

  return s1;
}