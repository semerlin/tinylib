/**
 * This file is part of the tinylib Library.
 *
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#include "tstack.h"
#include "tassert.h"

/****************************************************
 * functions 
 ****************************************************/
/**
 * @brief pop node frome stack
 * @param head - queue head
 * @return popped node
 */
tstack *t_stack_pop(tstack *head)
{
    T_ASSERT(NULL != head);
    tstack *ret = head->next;
    t_list_remove(head->next);
    return ret;
}


