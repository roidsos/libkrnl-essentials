#ifndef __STRING_H__
#define __STRING_H__

#include <types/stdtypes.h>

int memcmp(const void *, const void *, size_t);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memset(void *, int, size_t);

#endif // __STRING_H__