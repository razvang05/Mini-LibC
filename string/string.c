// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

// I used this site for some functions https://www.techiedelight.com/
// I used the manual for each function https://man7.org/linux/man-pages/

char *strcpy(char *destination, const char *source)
{
	if (destination == NULL) {
		return NULL;
	}
	int i;
	for (i = 0; source[i] != '\0'; i++) {
		destination[i] = source[i];
	}
	destination[i] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	if (destination == NULL) {
		return NULL;
	}
	size_t i;
	for (i = 0; i < len && source[i] != '\0'; ++i) {
		destination[i] = source[i];
	}
	for (; i < len; ++i) {
		destination[i] = '\0';
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	int destination_length = 0, i;
	while (destination[destination_length] != '\0') {
		destination_length++;
	}
	for (i = 0; source[i] != '\0'; i++) {
		destination[i + destination_length] = source[i];
	}
	destination[i + destination_length] = '\0';

	return destination;
}

// https://www.techiedelight.com/implement-strncat-function-c/

char *strncat(char *destination, const char *source, size_t len)
{
	while (*destination != '\0') {
		destination++;
	}
	for (; *source != '\0' && len > 0; len--) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	if (strlen(str1) > strlen(str2)) {
		return 1;
	} else if (strlen(str1) < strlen(str2)) {
		return -1;
	} else {
		while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
			str1++;
			str2++;
		}
	}

    return (unsigned char)(*str1) - (unsigned char)(*str2);
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i = 0;
	while (i < len && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
		i++;
	}

	return (unsigned char)(*str1) - (unsigned char)(*str2);
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	if(*str == '\0')
		return NULL;

	for (; *str != '\0'; str++) {
		if (*str == (char)c) {
			return (char*)str;
		}
	}

	if (c == '\0') {
		return (char*)str;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	const char *final_str;
	for (; *str != '\0'; str++) {
		if (*str == (char)c) {
			final_str = str;
		}
	}

	if (*final_str == (char)c)
		return (char*)final_str;
	return NULL;
}

// i had it chat gpt a generate a code for understanding
// i modified it
char *strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0') {
        return (char *)haystack;
    }

	for(; *haystack != '\0'; haystack++) {
        const char *h = haystack;
        const char *n = needle;

        for (; *n != '\0' && *h == *n; h++, n++) {
		}

        if (*n == '\0') {
            return (char *)haystack;
        }
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *last = NULL;

    if (*needle == '\0') {
        return (char *)haystack;
    }

    for (; *haystack != '\0'; haystack++) {
        const char *h = haystack;
        const char *n = needle;

        for (; *h != '\0' && *n != '\0' && *h == *n; h++, n++) {
        }

        if (*n == '\0') {
            last = (char *)haystack;
        }
    }

    return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	size_t i;
	for (i = 0; i < num; i++) {
		((char*)destination)[i] = ((const char*)source)[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *copy_dest = (char*)destination;
	const char *copy_source = (const char*)source;
	size_t i;

	if (copy_dest < copy_source) {
		for (i = 0 ; i < num; i++) {
			copy_dest[i] = copy_source[i];
		}
	} else if (copy_dest > copy_source) {
		for (i = num; i > 0; --i) {
			copy_dest[i-1] = copy_source[i-1];
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const char * copy_ptr1 = (char*)ptr1;
	const char * copy_ptr2 = (char*)ptr2;
	size_t i;

	for (i = 0; i < num; i++, copy_ptr1++, copy_ptr2++) {
		if (*copy_ptr1 < *copy_ptr2) {
			return -1;
		} else if (*copy_ptr1 > *copy_ptr2) {
			return 1;
		}
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *cop_source = (char*)source;
	size_t i;

	for (i = 0; i < num; i++, cop_source++) {
		*cop_source = (char)value;
	}
	return source;
}
