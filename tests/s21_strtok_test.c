#include "s21_check.h"

START_TEST(strtok_test_1) {
  char s21_source[100] = "!?Hello, world! How are you?!A!?";
  char source[100] = "!?Hello, world! How are you?!A!?";
  char *s21_token = s21_NULL;
  char *token = NULL;
  const char delimeter[] = " ";

  s21_token = s21_strtok(s21_source, delimeter);
  token = strtok(source, delimeter);
  ck_assert_str_eq(s21_token, token);

  while (token != NULL && s21_token != s21_NULL) {
    s21_token = s21_strtok(s21_NULL, delimeter);
    token = strtok(NULL, delimeter);
    ck_assert_pstr_eq(s21_token, token);
  }
}
END_TEST

START_TEST(strtok_test_2) {
  char s21_source[100] = "!?Hello, world! How are you?!A!?";
  char source[100] = "!?Hello, world! How are you?!A!?";
  char *s21_token = s21_NULL;
  char *token = NULL;
  const char delimeter[] = "";

  s21_token = s21_strtok(s21_source, delimeter);
  token = strtok(source, delimeter);
  ck_assert_str_eq(s21_token, token);

  while (token != NULL && s21_token != s21_NULL) {
    s21_token = s21_strtok(s21_NULL, delimeter);
    token = strtok(NULL, delimeter);
    ck_assert_pstr_eq(s21_token, token);
  }
}
END_TEST

START_TEST(strtok_test_3) {
  char s21_source[100] = "!?Hello, world! How are you?!A!?";
  char source[100] = "!?Hello, world! How are you?!A!?";
  char *s21_token = s21_NULL;
  char *token = NULL;
  const char delimeter[] = "? ,";

  s21_token = s21_strtok(s21_source, delimeter);
  token = strtok(source, delimeter);
  ck_assert_str_eq(s21_token, token);

  while (token != NULL && s21_token != s21_NULL) {
    s21_token = s21_strtok(s21_NULL, delimeter);
    token = strtok(NULL, delimeter);
    ck_assert_pstr_eq(s21_token, token);
  }
}
END_TEST

START_TEST(strtok_test_4) {
  char s21_source[100] = "!?Hello, world! How are you?!A!?";
  char source[100] = "!?Hello, world! How are you?!A!?";
  char *s21_token = s21_NULL;
  char *token = NULL;
  const char delimeter[] = "? ,!";

  s21_token = s21_strtok(s21_source, delimeter);
  token = strtok(source, delimeter);
  ck_assert_str_eq(s21_token, token);

  while (token != NULL && s21_token != s21_NULL) {
    s21_token = s21_strtok(s21_NULL, delimeter);
    token = strtok(NULL, delimeter);
    ck_assert_pstr_eq(s21_token, token);
  }
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s1 = suite_create("strtok_suite");
  TCase *tc1_1 = tcase_create("strtok_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strtok_test_1);
  tcase_add_test(tc1_1, strtok_test_2);
  tcase_add_test(tc1_1, strtok_test_3);
  tcase_add_test(tc1_1, strtok_test_4);

  return s1;
}
