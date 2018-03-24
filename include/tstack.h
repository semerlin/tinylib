/**
 * This file is part of the tinylib Library.
 *
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#ifndef _TSTACK_H_
  #define _TSTACK_H_

#include "ttypes.h"
#include "tlist.h"

T_BEGIN_DECLS


typedef tlist tstack;

#define t_stack_init_head(head) t_list_init_head(head)
#define t_stack_init_node(node) t_list_init_node(node)
#define t_stack_push(head, node) t_list_prepend(head, node)
T_EXTERN tstack *t_stack_pop(tstack *head);
#define t_stack_is_empty(head) t_list_is_empty(head)
#define t_stack_length(head) t_list_length(head)
#define t_stack_free(head, free_func) t_list_free(head, free_func)

/**
 * @brief foreach queue 
 * @param pos - current node pointer
 * @param queue - queue head
 */
#define t_stack_foreach(pos, head) \
        for (pos = (head)->next; pos != (head); pos = pos->next)


T_END_DECLS


#endif
