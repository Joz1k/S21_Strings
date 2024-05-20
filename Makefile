CC = gcc
CFLAGS = -Wall -Werror -Wextra
TFLAGS = -lcheck -lpthread -lm
TOBJS = $(wildcard tests/*.c)
OPEN = open

ifeq ($(shell uname), Linux)
	OPEN = xdg-open
	TFLAGS += -lrt -lsubunit -lgcov
endif

all: s21_string.a test gcov_report

s21_string.a:
	$(CC) -c $(CFLAGS) s21_string.c s21_sprintf.c
	ar rcs s21_string.a *.o

test:
	$(CC) $(CFLAGS) $(TOBJS) s21_string_tests.c s21_string.c s21_sprintf.c -o s21_tests $(TFLAGS)
	./s21_tests

gcov_report:
	$(CC) $(CFLAGS) --coverage $(TOBJS) s21_string_tests.c s21_string.c s21_sprintf.c -o s21_tests $(TFLAGS)
	./s21_tests
	lcov -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	$(OPEN) ./html_report/index.html

clean: 
	rm -rf *.o s21_string s21_tests *.gcda *.gcno *.info html_report *.a

rebuild: clean all
