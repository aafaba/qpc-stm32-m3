#ifndef  __NODE_LOG_H__
#define  __NODE_LOG_H__

#include <stdio.h>

#define __DEBUG__

#ifdef __DEBUG__
#define LOG(format, ...) printf(format"\n\r", ##__VA_ARGS__)
#else
#define LOG(format, ...)
#endif

#endif
