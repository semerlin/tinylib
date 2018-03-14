/**
 * This file is part of the tinylib library.
 *
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#ifndef _THASH_STRING_H_
#define _THASH_STRING_H_

#include "thlist.h"

T_BEGIN_DECLS

typedef void (*thash_func)(void *hash, void *args);

typedef struct _thash_string thash_string;

typedef struct 
{
    tchar *key;
    thlist_node node;
}thash_string_node;


T_EXTERN tint t_hash_string_init_node(thash_string_node *node, const tchar *key);
T_EXTERN thash_string_node *t_hash_string_new_node(const tchar *key);
T_EXTERN thash_string *t_hash_string_new(void);
T_EXTERN thash_string *t_hash_string_insert(thash_string *hash_string, thash_string_node *node);
T_EXTERN thash_string_node *t_hash_string_remove(thash_string *hash_string, const tchar *key);
T_EXTERN thash_string_node *t_hash_string_get(const thash_string *hash_string, const tchar *key);
T_EXTERN void t_hash_string_keys(const thash_string *hash_string, tchar **keys);
T_EXTERN tint t_hash_string_foreach(const thash_string *hash_string, thash_func hash_func, void *userdata);
T_EXTERN tbool t_hash_string_contain(const thash_string *hash_string, const tchar *key);
T_EXTERN tuint32 t_hash_string_count(const thash_string *hash_string);
T_EXTERN tuint32 t_hash_string_capacity(const thash_string *hash_string);
T_EXTERN void t_hash_string_free(thash_string *hash_string, tgeneric_func free_func);
T_EXTERN void t_hash_string_clear(thash_string *hash_string, tgeneric_func free_func);


T_END_DECLS

#endif /* _THASH_STRING_H_ */
