/**
 * This file is part of the tinylib library.
 *
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#ifndef _TQSORT_H_
#define _TQSORT_H_

#include "ttypes.h"

T_BEGIN_DECLS

T_EXTERN void t_qsort_tchar(tchar *data, tlong left, tlong right);
T_EXTERN void t_qsort_tuchar(tuchar *data, tlong left, tlong right);
T_EXTERN void t_qsort_tshort(tshort *data, tlong left, tlong right);
T_EXTERN void t_qsort_tushort(tushort *data, tlong left, tlong right);
T_EXTERN void t_qsort_tint(tint *data, tlong left, tlong right);
T_EXTERN void t_qsort_tuint(tuint *data, tlong left, tlong right);
T_EXTERN void t_qsort_tlong(tlong *data, tlong left, tlong right);
T_EXTERN void t_qsort_tulong(tulong *data, tlong left, tlong right);

T_END_DECLS

#endif /* _TQSORT_H_ */


