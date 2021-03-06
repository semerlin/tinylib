/**
 * This file is part of the tinylib library.
 *
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#ifndef _TTYPES_H_
#define _TTYPES_H_

#include "tconfig.h"
#include "tmacros.h"

T_BEGIN_DECLS

/* common types */
typedef char   tchar;
typedef short  tshort;
typedef long   tlong;
typedef int    tint;
typedef tint   tbool;

typedef unsigned char   tuchar;
typedef unsigned short  tushort;
typedef unsigned long   tulong;
typedef unsigned int    tuint;

typedef float   tfloat;
typedef double  tdouble;

/* boolean definition */
#ifndef	FALSE
#define	FALSE	(0)
#endif

#ifndef	TRUE
#define	TRUE	(!FALSE)
#endif


#ifndef NULL
#ifdef __cplusplus
    #define NULL    (0L)
#else
    #define NULL    ((void *)0)
#endif
#endif

#define UNUSED(x)   ((void)(x))

/* generic function */
typedef void (*tgeneric_func)(void *args);

T_END_DECLS

#endif /* _TTYPES_H_ */

