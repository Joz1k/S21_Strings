#include "s21_check.h"

/*string tests + different lengths*/
START_TEST(memcpy_test_1) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[100];
  s21_size_t n = 0;
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);
}
END_TEST

START_TEST(memcpy_test_2) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[100];
  s21_size_t n = 5;
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);
}
END_TEST

START_TEST(memcpy_test_3) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[100];
  s21_size_t n = 15;
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);
}
END_TEST

START_TEST(memcpy_test_4) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[100];
  s21_size_t n = 15;
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);
}
END_TEST

START_TEST(memcpy_test_5) {
  char source[] = "12345789 ABCDE";  // length = 15
  char destination[100];
  s21_size_t n = sizeof(source);
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);

  /*int tests + different lengths*/
}
END_TEST

START_TEST(memcpy_test_6) {
  int source[] = {1, 2, 3, 4, 5};
  int destination[100];
  s21_size_t n = 0;
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);
}
END_TEST

START_TEST(memcpy_test_7) {
  int source[] = {1, 2, 3, 4, 5};
  int destination[100];
  s21_size_t n = 2;
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);
}
END_TEST

START_TEST(memcpy_test_8) {
  int source[] = {1, 2, 3, 4, 5};
  int destination[100];
  s21_size_t n = 5;
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);
}
END_TEST

START_TEST(memcpy_test_9) {
  int source[] = {1, 2, 3, 4, 5};
  int destination[100];
  s21_size_t n = 10;
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);
}
END_TEST

START_TEST(memcpy_test_10) {
  int source[] = {1, 2, 3, 4, 5};
  int destination[100];
  s21_size_t n = sizeof(source);
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);

  /*struct tests + different lengths*/
}
END_TEST

START_TEST(memcpy_test_11) {
  struct TestStruct src_struct = {10, 'A', 3.14};
  struct TestStruct dest_struct;
  s21_size_t n = 0;
  ck_assert_mem_eq(s21_memcpy(&dest_struct, &src_struct, n),
                   memcpy(&dest_struct, &src_struct, n), n);
}
END_TEST

START_TEST(memcpy_test_12) {
  struct TestStruct src_struct = {10, 'A', 3.14};
  struct TestStruct dest_struct;
  s21_size_t n = sizeof(struct TestStruct) / 2;
  ck_assert_mem_eq(s21_memcpy(&dest_struct, &src_struct, n),
                   memcpy(&dest_struct, &src_struct, n), n);
}
END_TEST

START_TEST(memcpy_test_13) {
  struct TestStruct src_struct = {10, 'A', 3.14};
  struct TestStruct dest_struct;
  s21_size_t n = sizeof(struct TestStruct);
  ck_assert_mem_eq(s21_memcpy(&dest_struct, &src_struct, n),
                   memcpy(&dest_struct, &src_struct, n), n);

  /*int single + different lengths*/
}
END_TEST

START_TEST(memcpy_test_14) {
  int source = 5;
  int destination = 0;
  s21_size_t n = sizeof(source) * 0;
  ck_assert_mem_eq(s21_memcpy(&destination, &source, n),
                   memcpy(&destination, &source, n), n);
}
END_TEST

START_TEST(memcpy_test_15) {
  int source = 5;
  int destination = 0;
  s21_size_t n = sizeof(source);
  ck_assert_mem_eq(s21_memcpy(&destination, &source, n),
                   memcpy(&destination, &source, n), n);
}
END_TEST

START_TEST(memcpy_test_16) {
  int source = 5;
  int destination = 0;
  s21_size_t n = sizeof(source);
  ck_assert_mem_eq(s21_memcpy(&destination, &source, n),
                   memcpy(&destination, &source, n), n);

  /*array of pointers + different lengths*/
}
END_TEST

START_TEST(memcpy_test_17) {
  char *source[] = {"apple", "banana", "orange", "grape", "melon"};
  char *destination[100];
  s21_size_t n = sizeof(source);
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);
}
END_TEST

START_TEST(memcpy_test_18) {
  char *source[] = {"apple", "banana", "orange", "grape", "melon"};
  char *destination[100];
  s21_size_t n = sizeof(source);
  ck_assert_mem_eq(s21_memcpy(destination, source, n),
                   memcpy(destination, source, n), n);
}
END_TEST
Suite *suite_memcpy(void) {
  Suite *s1 = suite_create("memcpy_suite");
  TCase *tc1_1 = tcase_create("memcpy_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, memcpy_test_1);
  tcase_add_test(tc1_1, memcpy_test_2);
  tcase_add_test(tc1_1, memcpy_test_3);
  tcase_add_test(tc1_1, memcpy_test_4);
  tcase_add_test(tc1_1, memcpy_test_5);
  tcase_add_test(tc1_1, memcpy_test_6);
  tcase_add_test(tc1_1, memcpy_test_7);
  tcase_add_test(tc1_1, memcpy_test_8);
  tcase_add_test(tc1_1, memcpy_test_9);
  tcase_add_test(tc1_1, memcpy_test_10);
  tcase_add_test(tc1_1, memcpy_test_11);
  tcase_add_test(tc1_1, memcpy_test_12);
  tcase_add_test(tc1_1, memcpy_test_13);
  tcase_add_test(tc1_1, memcpy_test_14);
  tcase_add_test(tc1_1, memcpy_test_15);
  tcase_add_test(tc1_1, memcpy_test_16);
  tcase_add_test(tc1_1, memcpy_test_17);
  tcase_add_test(tc1_1, memcpy_test_18);

  return s1;
}
