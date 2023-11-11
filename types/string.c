#include "string.h"
#include "stdtypes.h"

char *strpbrk(const char *str, const char *charset) {
    while (*str != '\0') {
        const char *c = charset;
        while (*c != '\0') {
            if (*str == *c) {
                return (char *)str;
            }
            c++;
        }
        str++;
    }
    return NULL;
}

char *strtok(char *str, const char *delim) {
    static char *token = NULL;

    if (str != NULL) {
        token = str;
    } else if (token == NULL) {
        return NULL;
    }

    char *start = token;
    char *end = strpbrk(start, delim);

    if (end != NULL) {
        *end = '\0';
        token = end + 1;
    } else {
        token = NULL;
    }

    return start;
}

char *strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }

    if (c == '\0') {
        return (char *)str;
    }

    return NULL;
}
void str_reverse(char *s) {
    size_t i = 0;
    size_t j = strlen(s) - 1;
    char tmp;
    while (i < j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

void strcat(char *s1, char *s2) {
    char *start = s1;
    while (*start != '\0')
        start++;
    while (*s2 != '\0')
        *start++ = *s2++;
    *start = '\0';
}

void str_append(char *s, char c) {
    size_t i = 0;
    while (s[i] != '\0')
        i++;
    s[i] = c;
    s[i + 1] = '\0';
}

char *strcpy(char *dest, char *src) {
    size_t i;

    for (i = 0; src[i]; i++) {
        dest[i] = src[i];
    }

    dest[i] = 0;

    return dest;
}

char *strncpy(char *dest, char *src, size_t n) {
    size_t i;

    for (i = 0; i < n && src[i]; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = 0;
    }

    return dest;
}

int strcmp(char *s1, char *s2) {
    for (size_t i = 0;; i++) {
        char c1 = s1[i], c2 = s2[i];
        if (c1 != c2) {
            return c1 - c2;
        }
        if (!c1) {
            return 0;
        }
    }
}

int strncmp(char *s1, char *s2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        char c1 = s1[i], c2 = s2[i];
        if (c1 != c2) {
            return c1 - c2;
        }
        if (!c1) {
            return 0;
        }
    }

    return 0;
}

size_t strlen(char *str) {
    size_t len;

    for (len = 0; str[len]; len++)
        ;

    return len;
}