#include "s21_check.h"

START_TEST(strerror_test_1) {
  for (int i = ERR_FIRST - 1; i <= ERR_LAST + 1; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s1 = suite_create("strerror_suite");
  TCase *tc1_1 = tcase_create("strerror_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strerror_test_1);

  return s1;
}
