#include <types/stdtypes.h>
#include <stdbool.h>

uint8_t strlen(char* str);
bool strcmp(char* str1,char* str2);

#ifdef HEAP_ACCESSABLE
char** split(char* str,char spliton);
#endif