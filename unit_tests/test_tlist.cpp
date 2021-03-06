/**
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#include "gtest/gtest.h"
#include "tlist.h"

struct num_list
{
    int num;
    tlist node;
};

#ifdef T_ENABLE_ASSERT
TEST(TlistTest, Death)
{
    tlist head, node;
    EXPECT_DEATH(t_list_init_head(NULL), "");
    EXPECT_DEATH(t_list_init_node(NULL), "");
    EXPECT_DEATH(t_list_prepend(NULL, &node), "");
    EXPECT_DEATH(t_list_prepend(&head, NULL), "");
    EXPECT_DEATH(t_list_append(&head, NULL), "");
    EXPECT_DEATH(t_list_append(NULL, &node), "");
    EXPECT_DEATH(t_list_is_empty(NULL), "");
    EXPECT_DEATH(t_list_is_last(NULL, &node), "");
    EXPECT_DEATH(t_list_is_first(NULL, &node), "");
    EXPECT_DEATH(t_list_length(NULL), "");
    EXPECT_DEATH(t_list_free(NULL, NULL), "");
}
#endif

TEST(TlistTest, Init)
{
    tlist head = {NULL, NULL};
    tlist node = {&head, &head};
    t_list_init_head(&head);
    EXPECT_EQ(&head, head.prev);
    EXPECT_EQ(&head, head.next);
    t_list_init_node(&node);
    EXPECT_EQ(NULL, node.prev);
    EXPECT_EQ(NULL, node.next);
}

TEST(TlistTest, Add)
{
    tlist head, node1, node2, node3;
    t_list_init_head(&head);
    t_list_init_node(&node1);
    t_list_init_node(&node2);
    t_list_init_node(&node3);
    t_list_prepend(&head, &node1);
    EXPECT_EQ(&node1, head.next);
    EXPECT_EQ(&node1, head.prev);
    EXPECT_EQ(&head, node1.next);
    EXPECT_EQ(&head, node1.prev);
    t_list_prepend(&head, &node2);
    EXPECT_EQ(&node2, head.next);
    EXPECT_EQ(&node1, head.prev);
    EXPECT_EQ(&head, node1.next);
    EXPECT_EQ(&node2, node1.prev);
    EXPECT_EQ(&head, node2.prev);
    EXPECT_EQ(&node1, node2.next);
    t_list_append(&head, &node3);
    EXPECT_EQ(&node3, node1.next);
    EXPECT_EQ(&node1, node3.prev);
    EXPECT_EQ(&head, node3.next);
}

TEST(TlistTest, Remove)
{
    tlist head, node1, node2, node3;
    t_list_init_head(&head);
    t_list_init_node(&node1);
    t_list_init_node(&node2);
    t_list_init_node(&node3);
    t_list_append(&head, &node1);
    t_list_append(&head, &node2);
    t_list_append(&head, &node3);
    t_list_remove(&node2);
    EXPECT_EQ(&node1, head.next);
    EXPECT_EQ(&node3, head.prev);
    EXPECT_EQ(&node3, node1.next);
    EXPECT_EQ(&head, node1.prev);
    EXPECT_EQ(&head, node3.next);
    EXPECT_EQ(&node1, node3.prev);
    EXPECT_EQ(NULL, node2.next);
    EXPECT_EQ(NULL, node2.prev);
}

int num = 0;
void free_func(void *args)
{
    num ++;
}

TEST(TlistTest, Free)
{
    tlist head, node1, node2, node3;
    t_list_init_head(&head);
    t_list_init_node(&node1);
    t_list_init_node(&node2);
    t_list_init_node(&node3);
    t_list_append(&head, &node1);
    t_list_append(&head, &node2);
    t_list_append(&head, &node3);
    t_list_free(&head, free_func);
    EXPECT_EQ(3, num);
}



TEST(TlistTest, Foreach)
{
    tlist head;
    struct num_list node1, node2, node3;
    node1.num = 1;
    node2.num = 2;
    node3.num = 3;
    t_list_init_head(&head);
    t_list_init_node(&node1.node);
    t_list_init_node(&node2.node);
    t_list_init_node(&node3.node);
    t_list_append(&head, &node1.node);
    t_list_append(&head, &node2.node);
    t_list_append(&head, &node3.node);

    tlist *pos;
    int i = 0;
    t_list_foreach(pos, &head)
    {
        ++i;
        EXPECT_EQ(i, T_CONTAINER_OF(pos, num_list, node)->num);
    }
}

TEST(TlistTest, Check)
{
    tlist head, node1, node2, node3;
    t_list_init_head(&head);
    t_list_init_node(&node1);
    t_list_init_node(&node2);
    t_list_init_node(&node3);
    EXPECT_TRUE(t_list_is_empty(&head));
    EXPECT_FALSE(t_list_is_last(&head, &node1));
    EXPECT_FALSE(t_list_is_first(&head, &node1));
    EXPECT_EQ(0, t_list_length(&head));
    t_list_append(&head, &node1);
    EXPECT_EQ(1, t_list_length(&head));
    t_list_append(&head, &node2);
    t_list_append(&head, &node3);
    EXPECT_EQ(3, t_list_length(&head));
    t_list_remove(&node2);
    EXPECT_FALSE(t_list_is_empty(&head));
    EXPECT_TRUE(t_list_is_last(&head, &node3));
    EXPECT_TRUE(t_list_is_first(&head, &node1));
    EXPECT_EQ(2, t_list_length(&head));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}

