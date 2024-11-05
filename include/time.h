#ifndef	__TIME_H__
#define	__TIME_H__	1

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef long time_t;
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};
unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *req, const struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
