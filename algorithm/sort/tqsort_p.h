/**
 * This file is part of the tinylib library.
 *
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#include "ttypes.h"

/**
 * @brief quick sort
 * @param data - data need to sort
 * @param left - data left boundary
 * @param right - data right boundary
 */
void _func(_type *data, tlong left, tlong right)
{
    if (NULL == data)
    {
        return ;
    }

    if (left >= right)
    {
        return ;
    }

    tlong i = left;
    tlong j = right;
    _type key = data[i];

    while (i < j)
    {
        while ((i < j) && (data[j] >= key))
        {
            j --;
        }
        data[i] = data[j];

        while ((i < j) && (data[i] <= key))
        {
            i ++;
        }
        data[j] = data[i];
    }

    data[i] = key;
    _func(data, left, i - 1);
    _func(data, i + 1, right);
}

#undef _func
#undef _type

