

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BRED "\x1b[1;31m"
#define BGREEN "\x1b[1;32m"
#define BYELLOW "\x1b[1;33m"
#define BBLUE "\x1b[1;34m"
#define BMAGENTA "\x1b[1;35m"
#define BCYAN "\x1b[1;36m"

#define RED "\x1b[0;31m"
#define GREEN "\x1b[0;32m"
#define YELLOW "\x1b[0;33m"
#define BLUE "\x1b[0;34m"
#define MAGENTA "\x1b[0;35m"
#define RES "\x1b[0;0m"

#define seeLevel 0

#define logInfo(message, level)                                                           \
    if (seeLevel <= level)                                                                \
    {                                                                                     \
        (printf(BGREEN "INFO   " GREEN "%s  %s:%d  " RES, __TIME__, __FILE__, __LINE__)); \
        message;                                                                          \
        printf("\n");                                                                     \
    }

#define logProccess(message, level)                                                       \
    if (seeLevel <= level)                                                                \
    {                                                                                     \
        printf(BYELLOW "TASK   " YELLOW "%s  %s:%d  " RES, __TIME__, __FILE__, __LINE__); \
        message;                                                                          \
        printf("\n");                                                                     \
    }

#define logComplete(message, level)                                                     \
    if (seeLevel <= level)                                                              \
    {                                                                                   \
        printf(BGREEN "DONE   " GREEN "%s  %s:%d  " RES, __TIME__, __FILE__, __LINE__); \
        message;                                                                        \
        printf("\n");                                                                   \
    }

#define logTrace(message, level)                                                      \
    if (seeLevel <= level)                                                            \
    {                                                                                 \
        printf(BBLUE "TRACE  " BLUE "%s  %s:%d  " RES, __TIME__, __FILE__, __LINE__); \
        message;                                                                      \
        printf("\n");                                                                 \
    }

#define logWarning(message, level)                                                         \
    if (seeLevel <= level)                                                                 \
    {                                                                                      \
        printf(BMAGENTA "WARN  " MAGENTA "%s  %s:%d  " RES, __TIME__, __FILE__, __LINE__); \
        message;                                                                           \
        printf("\n");                                                                      \
    }

#define logError(message)                                                      \
    printf(BRED "ERROR  " RED "%s %s:%d  " RES, __TIME__, __FILE__, __LINE__); \
    message;                                                                   \
    printf("\n");
// any log with a level equal or above the current logging level will be shown anything else will be omited
