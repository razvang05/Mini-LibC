// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

// i used https://man7.org/linux/man-pages/ for each function mm
// i asked chat gpt to give me an idea

void *malloc(size_t size)
{
	if(size == 0)
		return NULL;
	void *res = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if(res == MAP_FAILED) {
		return NULL;
	}
	int res1 = mem_list_add(res, size);
	if(res1 == -1) {
		return NULL;
	}

	return res;
}

void *calloc(size_t nmemb, size_t size)
{
	void *res = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(res == MAP_FAILED) {
		return NULL;
	}

	if(mem_list_add(res, nmemb * size) == -1) {
		munmap(res, nmemb * size);
		return NULL;
	}
	return res;
}

void free(void *ptr)
{
	if(ptr == NULL) {
		return;
	}
	struct mem_list *ptr1;

	ptr1 = mem_list_find(ptr);
	if (ptr1 != NULL) {
		int res = munmap(ptr, ptr1->len);
		if(res == 0) {
			mem_list_del(ptr);
		}
	}
}

void *realloc(void *ptr, size_t size)
{
    if (size == 0) {
		return NULL;
	}

	if(ptr == NULL) {
		return malloc(size);
	}
	struct mem_list *ptr1 = mem_list_find(ptr);

	if(ptr1 != NULL) {
		void *new_ptr1 = mremap(ptr, ptr1->len, size, 0);
		if(new_ptr1 != MAP_FAILED) {
			mem_list_add(new_ptr1, size);
		} else {
			return NULL;
		}
		return new_ptr1;
	}
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, nmemb * size);

	return NULL;
}
