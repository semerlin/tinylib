/**
 * This file is part of the tinylib Library.
 *
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#include "tqueue.h"
#include "tassert.h"

/****************************************************
 * functions 
 ****************************************************/
tqueue *t_queue_pop(tqueue *head)
{
    T_ASSERT(NULL != head);
    tqueue *ret = head->next;
    if (NULL == ret)
    {
        return NULL;
    }
    else
    {
        ret->next->prev = head;
        head->next = ret->next;
        ret->prev = NULL;
        ret->next = NULL;
        return ret;
    }
}


