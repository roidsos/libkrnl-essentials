#include <types/stdtypes.h>
#include <stdbool.h>

void str_reverse(char *s);
void str_append(char *s, char c);

char *strpbrk(const char *str, const char *charset);
char *strtok(char *str, const char *delim);
char *strchr(const char *str, int c);
char *strcpy(char *dest, char *src);
char *strncpy(char *dest, char *src, size_t n);
void strcat(char *s1, char *s2);
int strcmp(char *s1, char *s2);
int strncmp(char *s1, char *s2, size_t n);
size_t strlen(char *str);

#ifdef HEAP_ACCESSABLE
char** split(char* str,char spliton);
void split_free(char **substrings);
#endif