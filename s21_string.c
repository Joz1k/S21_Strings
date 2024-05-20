#include "s21_string.h"

int s21_atoi(const char *str) {
  int result = 0;
  int sign = 1;
  int i = 0;
  int sign_or_digit_printed = 0;

  while (str[i] != '\0') {
    if (str[i] == '-' && !sign_or_digit_printed) {
      sign = -1;
      sign_or_digit_printed = 1;
    } else if (str[i] >= '0' && str[i] <= '9') {
      result = result * 10 + (str[i] - '0');
      sign_or_digit_printed = 1;
    } else if (str[i] == '+' && !sign_or_digit_printed) {
      sign_or_digit_printed = 1;
    } else if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') &&
               !sign_or_digit_printed) {
    } else {
      break;
    }
    i++;
  }
  return result * sign;
}

char *s21_insert(char *str1, char *str2, int start_index) {
  int length_str1 = s21_strlen(str1);
  int length_str2 = s21_strlen(str2);
  int length_new_str = length_str1 + length_str2;
  int flag_start = 0;
  int flag_str1 = 0;
  int flag_str2 = 0;
  char *new_str = (char *)malloc((length_new_str + 1) * sizeof(char));
  for (int i = 0; i <= length_new_str; i++) {
    if (i == start_index || flag_start >= 1) {
      flag_start++;
      new_str[i] = str2[flag_str2];
      flag_str2++;
      if (flag_start == length_str2) flag_start = 0;
    } else {
      new_str[i] = str1[flag_str1];
      flag_str1++;
    }
  }
  new_str[length_new_str] = '\0';
  return new_str;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *myStr = (unsigned char *)str;
  unsigned char *found = s21_NULL;
  while (n-- && !found) {
    if (c == *myStr) {
      found = myStr;
      break;
    }
    myStr++;
  }
  return found;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *cdest = (unsigned char *)dest;
  unsigned char *csrc = (unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    cdest[i] = csrc[i];
  }

  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ustr = (unsigned char *)str;
  unsigned char uc = (unsigned char)c;

  for (s21_size_t i = 0; i < n; i++) {
    ustr[i] = uc;
  }

  return str;
}

char *s21_strchr(const char *str, int c) {
  char *found = s21_NULL;
  char i = *str;
  while (i != '\0' && !found) {
    if (*str == c) {
      found = (char *)str;
      break;
    }
    str++;
    i = *str;
  }
  if (c == '\0') {
    found = (char *)str;
  }

  return found;
}

int s21_strcspn(char *str1, char *str2) {
  int size1 = s21_strlen(str1);
  int size2 = s21_strlen(str2);
  int flag = 0;
  int temp1 = 0;
  int temp2 = 0;
  for (int i = 0; i < size1 && flag != 1; i++) {
    for (int j = 0; j < size2 && flag != 1; j++) {
      if (str1[i] == str2[j]) {
        temp1++;
      }
    }
    if (temp1 == 0) {
      temp2++;
    } else
      flag = 1;
    temp1 = 0;
  }
  return temp2;
}

s21_size_t s21_strlen(const char *str) {
  int result = 0;
  while (*(str + result) != '\0') result = result + 1;
  return result;
}

char *s21_strpbrk(char *str1, char *str2) {
  int size1 = s21_strlen(str1);
  int size2 = s21_strlen(str2);
  int flag = 0;
  int index = 0;
  int result = 0;
  for (int i = 0; i < size1 && flag != 1; i++) {
    index++;
    for (int j = 0; j < size2 && flag != 1; j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
      }
    }
  }
  result = index;
  if (flag == 0) return s21_NULL;
  return &str1[result - 1];
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  // copying
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  // fill with zeros if the length is less then n;
  for (; i < n; i++) {
    dest[i] = '\0';
  }
  return dest;
}

char *s21_strrchr(const char *str, int c) {
  char *found = s21_NULL;
  for (s21_size_t i = s21_strlen(str); i > 0; i--) {
    if (str[i] == c) {
      found = (char *)(str + i);
      break;
    }
  }
  return found;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *found = s21_NULL;
  if (*needle != '\0') {
    while (*haystack != '\0') {
      s21_size_t nLen = s21_strlen(needle);
      if (!s21_strncmp(haystack, needle, nLen)) {
        found = (char *)haystack;
        break;
      }
      haystack++;
    }
  } else {
    found = (char *)haystack;
  }
  return found;
}

char *s21_strtok(char *str, const char *delim) {
  static int finished = 0;
  static int begin = 0;
  static int end = 0;
  static char *tmp = s21_NULL;

  char *res = s21_NULL;

  if (str != s21_NULL) {
    tmp = str;
    begin = 0;
    end = 0;
    finished = 0;
  } else {
    begin = end;
  }

  int token_found = 0;

  while (tmp[end] != '\0' && token_found != 1) {
    int j = 0;
    while (delim[j] != '\0') {
      if (delim[j] == tmp[end]) {
        tmp[end] = '\0';
        if (begin != end) {
          token_found = 1;
          res = tmp + begin;
        } else {
          begin++;
        }
        break;
      }
      j++;
    }

    end++;
  }

  if (tmp[end] == '\0' && token_found == 0 && finished == 0) {
    finished = 1;
    if (begin != end) {
      res = tmp + begin;
    }
  }
  return res;
}

void *s21_to_lower(const char *str) {
  char *temp = s21_NULL;
  if (str != s21_NULL) {
    temp = (char *)malloc(sizeof(char) * (s21_strlen(str) + 1));
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        temp[i] = (str[i] - 'A') + 'a';
      } else {
        temp[i] = str[i];
      }
    }
    temp[s21_strlen(str)] = '\0';
  }
  return temp;
}

void *s21_to_upper(const char *str) {
  char *temp = s21_NULL;
  if (str != s21_NULL) {
    temp = (char *)malloc(sizeof(char) * (s21_strlen(str) + 1));
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        temp[i] = (str[i] - 'a') + 'A';
      } else {
        temp[i] = str[i];
      }
    }
    temp[s21_strlen(str)] = '\0';
  }
  return temp;
}

char *s21_trim(char *str1, char *str2) {
  int length_str1 = s21_strlen(str1);
  int length_str2 = s21_strlen(str2);
  int flag = 0;
  int iter = 0;
  char *new_str = (char *)malloc((length_str1 + 1) * sizeof(char));
  for (int i = 0; i < length_str1; i++) {
    for (int j = 0; j < length_str2 && flag != 1; j++) {
      if (str1[i] == str2[j]) flag = 1;
    }
    if (flag == 0) {
      new_str[iter] = str1[i];
      iter++;
    }
    flag = 0;
  }
  new_str[iter] = '\0';
  return new_str;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int cmp_res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if ((cmp_res = *((unsigned char *)(str1 + i)) -
                   *((unsigned char *)(str2 + i))) != 0) {
      break;
    }
  }
  return cmp_res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int cmp_res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if ((cmp_res = *(str1 + i) - *(str2 + i)) != 0 || *(str1 + i) == '\0' ||
        *(str2 + i) == '\0') {
      break;
    }
  }
  return cmp_res;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t len_dest = s21_strlen(dest);
  s21_size_t len_src = s21_strlen(src);
  int index = 0;
  for (s21_size_t i = 0; i < n; i++) {
    index = i;
    if (i < len_src) {
      dest[len_dest + i] = src[i];
    } else {
      break;
    }
  }
  dest[len_dest + index] = '\0';
  return dest;
}

char *s21_strerror(int errnum) {
  const char *errors_array[] = s21_errors_list;
  static char result[256];
  s21_memset(result, '\0', 256);
  if (errnum < ERR_FIRST || errnum > ERR_LAST) {
#ifdef __linux__
    s21_sprintf(result, "Unknown error %d", errnum);
#elif __APPLE__ || __MACH__
    s21_sprintf(result, "Unknown error: %d", errnum);
#endif
  } else {
    s21_strncpy(result, errors_array[errnum], s21_strlen(errors_array[errnum]));
  }
  return result;
}

int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }