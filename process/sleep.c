#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <internal/syscall.h>

// i used https://man7.org/linux/man-pages/man3/sleep.3.html

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;

    if (nanosleep(&req, &rem) == -1) {
        return rem.tv_sec;
    } else {
        return 0;
    }
}
