#include "s21_string.h"
#include "tests/s21_check.h"

void run_testcase(Suite *testcase);
void run_tests(void);

int main(void) {
  run_tests();
  return 0;
}

void run_tests(void) {
  Suite *list_cases[] = {suite_strncmp(),  suite_memcmp(),
                         suite_strerror(), suite_strncat(),
                         suite_atoi(),     suite_insert(),
                         suite_memchr(),   suite_memcpy(),
                         suite_memset(),   suite_sprintf(),
                         suite_strchr(),   suite_strcspn(),
                         suite_strlen(),   suite_strncpy(),
                         suite_strrchr(),  suite_strstr(),
                         suite_strtok(),   suite_to_lower(),
                         suite_to_upper(), suite_trim(),
                         suite_strpbrk(),  NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

void run_testcase(Suite *testcase) {
  setlocale(LC_ALL, "en_US.UTF-8");
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}