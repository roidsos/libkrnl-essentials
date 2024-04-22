#include "string.h"

void *memchr(const void *s, int c, size_t n)
{
	const unsigned char uc = c;
	const unsigned char *su;

	for (su = s; n > 0; ++su, --n) {
		if (*su == uc) {
			return (void *)su;
		}
	}

	return NULL;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *su1;
	const unsigned char *su2;

	for (su1 = s1, su2 = s2; n > 0; ++su1, ++su2, --n) {
		if (*su1 != *su2) {
			return ((*su1 < *su2) ? -1 : 1);
		}
	}

	return 0;
}

void *memcpy(void *s1, const void * s2, size_t n)
{
	char *su1;
	const char *su2;

	for (su1 = s1, su2 = s2; n > 0; ++su1, ++su2, --n) {
		*su1 = *su2;
	}

	return s1;
}

void *memmove(void *s1, const void *s2, size_t n)
{
	char *sc1;
	const char *sc2;

	sc1 = s1;
	sc2 = s2;
	if (sc2 < sc1 && sc1 < sc2 + n) {
		for (sc1 += n, sc2 += n; n > 0; --n) {
			*--sc1 = *--sc2;
		}
	} else {
		for (; n > 0; --n) {
			*sc1++ = *sc2++;
		}
	}

	return s1;
}

void *memset(void *s, int c, size_t n)
{
	const unsigned char uc = c;
	unsigned char *su;

	for (su = s; n > 0; ++su, --n) {
		*su = uc;
	}

	return s;
}