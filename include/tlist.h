/**
 * This file is part of the tinylib Library.
 *
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#ifndef _TLIST_H_
#define _TLIST_H_

#include "ttypes.h"

T_BEGIN_DECLS


typedef struct _tlist tlist;

struct _tlist
{
    tlist *prev;
    tlist *next;
};


T_EXTERN void t_list_init_head(tlist *head);
T_EXTERN void t_list_init_node(tlist *node);
T_EXTERN void t_list_prepend(tlist *head, tlist *node);
T_EXTERN void t_list_append(tlist *head, tlist *node);
T_EXTERN void t_list_remove(tlist *node);
T_EXTERN tbool t_list_is_empty(const tlist *head);
T_EXTERN tbool t_list_is_last(const tlist *head, const tlist *node);
T_EXTERN tbool t_list_is_first(const tlist *head, const tlist *node);
T_EXTERN tuint32 t_list_length(const tlist *head);
T_EXTERN void t_list_free(tlist *head, tgeneric_func free_func);

/**
 * @brief list
 * @param pos - current node pointer
 * @param head - list head
 */
#define t_list_foreach(pos, head) \
        for (pos = (head)->next; pos != (head); pos = pos->next)


T_END_DECLS




#endif
