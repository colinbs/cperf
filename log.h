#ifndef LOG_H
#define LOG_H

#include <stdio.h>

void cperf_dbg(const char *frmt, ...) __attribute__((format(printf, 1, 2)));

#define CPERF_DBG(fmt, ...) cperf_dbg(fmt, ## __VA_ARGS__)
#define CPERF_DBG1(a) cperf_dbg(a)

#endif
