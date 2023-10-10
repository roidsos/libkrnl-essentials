#include <types/stdtypes.h>
#include <stdbool.h>

char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
size_t strlen(const char *str);

#ifdef HEAP_ACCESSABLE
char** split(char* str,char spliton);
#endif