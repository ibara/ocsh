/*
 * Multi-platform support.
 */

#ifndef _OCSH_PORTABLE_H_
#define _OCSH_PORTABLE_H_

/*
 * Includes
 */

#ifdef __linux__
#include <sys/file.h>
#include <sys/types.h>

#include <grp.h>
#include <stdint.h>
#include <stdlib.h>
#endif /* __linux__ */

#include <sys/param.h>
#include <sys/time.h>

#ifdef __APPLE__
#include <mach/clock.h>
#include <mach/mach.h>
#endif /* __APPLE__ */

#include <time.h>

#include "config.h"

/*
 * Defines
 */

#ifndef NSIG
#define NSIG	33
#endif /* !NSIG */

#ifndef RLIMIT_CPU
#define RLIMIT_CPU	0
#endif /* !RLIMIT_CPU */

#ifndef RLIMIT_FSIZE
#define RLIMIT_FSIZE	1
#endif /* !RLIMIT_FSIZE */

#ifndef RLIMIT_DATA
#define RLIMIT_DATA	2
#endif /* !RLIMIT_DATA */

#ifndef RLIMIT_STACK
#define RLIMIT_STACK	3
#endif /* !RLIMIT_STACK */

#ifndef RLIMIT_CORE
#define RLIMIT_CORE	4
#endif /* !RLIMIT_CORE */

#ifndef RLIMIT_RSS
#define RLIMIT_RSS	5
#endif /* !RLIMIT_RSS */

#ifndef RLIMIT_MEMLOCK
#define RLIMIT_MEMLOCK	6
#endif /* !RLIMIT_MEMLOCK */

#ifndef RLIMIT_NPROC
#define RLIMIT_NPROC	7
#endif /* !RLIMIT_NPROC */

#ifndef RLIMIT_NOFILE
#define RLIMIT_NOFILE	8
#endif /* !RLIMIT_NOFILE */

/* Convert clock_gettime() to clock_get_time() on Max OS X */
#ifdef __APPLE__
#define clock_gettime(x, y)						\
	clock_serv_t cclock;						\
	mach_timespec_t mts;						\
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock); \
	clock_get_time(cclock, &mts);					\
	mach_port_deallocate(mach_task_self(), cclock);			\
	(y)->tv_sec = mts.tv_sec;					\
	(y)->tv_nsec = mts.tv_nsec;
#endif /* __APPLE__ */

/* Cygwin already has a sys_signame but we want to use our own */
#ifdef __CYGWIN__
#define sys_signame	esys_signame
#endif /* __CYGWIN__ */

/* From OpenBSD sys/time.h */
#ifndef __OpenBSD__
#define timespeccmp(tsp, usp, cmp)                                      \
        (((tsp)->tv_sec == (usp)->tv_sec) ?                             \
            ((tsp)->tv_nsec cmp (usp)->tv_nsec) :                       \
            ((tsp)->tv_sec cmp (usp)->tv_sec))

#define timespecsub(tsp, usp, vsp)                                      \
        do {                                                            \
                (vsp)->tv_sec = (tsp)->tv_sec - (usp)->tv_sec;          \
                (vsp)->tv_nsec = (tsp)->tv_nsec - (usp)->tv_nsec;       \
                if ((vsp)->tv_nsec < 0) {                               \
                        (vsp)->tv_sec--;                                \
                        (vsp)->tv_nsec += 1000000000L;                  \
                }                                                       \
        } while (0)
#endif /* !__OpenBSD__ */

/*
 * Prototypes
 */

#ifdef NEED_REALLOCARRAY
void	 *reallocarray(void *, size_t, size_t);
#endif /* NEED_REALLOCARRAY */

#ifdef NEED_STRTONUM
long long strtonum(const char *numstr, long long minval, long long maxval,
		   const char **errstrp);
#endif /* NEED_STRTONUM */

/*
 * Externs
 */

#ifdef NEED_SIGNAME
extern const char *const sys_signame[NSIG];
#endif /* NEED_SIGNAME */

#endif /* !_OCSH_PORTABLE_H_ */
