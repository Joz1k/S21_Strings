#include "s21_check.h"

/*different lengths*/
START_TEST(memset_test_1) {
  char source[] = "12345789 ABCDE";  // length = 15
  int c = 'a';
  s21_size_t n = sizeof(source) * 0;
  ck_assert_mem_eq(s21_memset(source, c, n), memset(source, c, n),
                   sizeof(source));
}
END_TEST

START_TEST(memset_test_2) {
  char source[] = "12345789 ABCDE";  // length = 15
  int c = 'a';
  s21_size_t n = sizeof(source);
  ck_assert_mem_eq(s21_memset(source, c, n), memset(source, c, n),
                   sizeof(source));
}
END_TEST

START_TEST(memset_test_3) {
  char source[] = "12345789 ABCDE";  // length = 15
  int c = 'a';
  s21_size_t n = sizeof(source) / 2;
  ck_assert_mem_eq(s21_memset(source, c, n), memset(source, c, n),
                   sizeof(source));
}
END_TEST

START_TEST(memset_test_4) {
  char source[] = "12345789 ABCDE";  // length = 15
  int c = 'a';
  s21_size_t n = 3;
  ck_assert_mem_eq(s21_memset(source + 3, c, n), memset(source + 3, c, n),
                   sizeof(source));
}
END_TEST

START_TEST(memset_test_5) {
  char source[] = "12345789 ABCDE";  // length = 15
  int c = 'a';
  s21_size_t n = 3;
  ck_assert_mem_eq(s21_memset(source + 12, c, n), memset(source + 12, c, n),
                   sizeof(source));
}
END_TEST

Suite *suite_memset(void) {
  Suite *s1 = suite_create("memset_suite");
  TCase *tc1_1 = tcase_create("memset_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, memset_test_1);
  tcase_add_test(tc1_1, memset_test_2);
  tcase_add_test(tc1_1, memset_test_3);
  tcase_add_test(tc1_1, memset_test_4);
  tcase_add_test(tc1_1, memset_test_5);

  return s1;
}
