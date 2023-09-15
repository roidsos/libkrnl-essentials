#include <types/stdtypes.h>
#include <stdbool.h>

uint8_t strlen(char* str);
bool strcmp(char* str1,char* str2);
bool strncmp(char *str1, char *str2, int n);

#ifdef HEAP_ACCESSABLE
char** split(char* str,char spliton);
#endif