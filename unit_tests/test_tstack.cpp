/**
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#include "gtest/gtest.h"
#include "tstack.h"

struct num_list
{
    int num;
    tstack node;
};

#ifdef T_ENABLE_ASSERT
TEST(TstackTest, Death)
{
    tstack head, node;
    EXPECT_DEATH(t_stack_init_head(NULL), "");
    EXPECT_DEATH(t_stack_init_node(NULL), "");
    EXPECT_DEATH(t_stack_push(&head, NULL), "");
    EXPECT_DEATH(t_stack_push(NULL, &node), "");
    EXPECT_DEATH(t_stack_pop(NULL), "");
    EXPECT_DEATH(t_stack_is_empty(NULL), "");
    EXPECT_DEATH(t_stack_length(NULL), "");
    EXPECT_DEATH(t_stack_free(NULL, NULL), "");
}
#endif

TEST(TstackTest, Init)
{
    tstack head = {NULL, NULL};
    tstack node = {&head, &head};
    t_stack_init_head(&head);
    EXPECT_EQ(&head, head.prev);
    EXPECT_EQ(&head, head.next);
    t_stack_init_node(&node);
    EXPECT_EQ(NULL, node.prev);
    EXPECT_EQ(NULL, node.next);
}

TEST(tstackTest, Append)
{
    tstack head, node1, node2, node3;
    t_stack_init_head(&head);
    t_stack_init_node(&node1);
    t_stack_init_node(&node2);
    t_stack_init_node(&node3);
    t_stack_push(&head, &node1);
    t_stack_push(&head, &node2);
    t_stack_push(&head, &node3);
    EXPECT_EQ(&head, node1.next);
    EXPECT_EQ(&node2, node1.prev);
    EXPECT_EQ(&node1, node2.next);
    EXPECT_EQ(&node3, node2.prev);
    EXPECT_EQ(&node2, node3.next);
    EXPECT_EQ(&head, node3.prev);
    EXPECT_EQ(&node3, head.next);
    EXPECT_EQ(&node1, head.prev);
}

TEST(tstackTest, Pop)
{
    tstack head, node1, node2, node3;
    t_stack_init_head(&head);
    t_stack_init_node(&node1);
    t_stack_init_node(&node2);
    t_stack_init_node(&node3);
    t_stack_push(&head, &node1);
    t_stack_push(&head, &node2);
    t_stack_push(&head, &node3);
    t_stack_pop(&head);
    EXPECT_EQ(&node2, head.next);
    EXPECT_EQ(&node1, head.prev);
    EXPECT_EQ(&node1, node2.next);
    EXPECT_EQ(&head, node2.prev);
    EXPECT_EQ(&head, node1.next);
    EXPECT_EQ(&node2, node1.prev);
    EXPECT_EQ(NULL, node3.next);
    EXPECT_EQ(NULL, node3.prev);
}

int num = 0;
void free_func(void *args)
{
    num ++;
}

TEST(tstackTest, Free)
{
    tstack head, node1, node2, node3;
    t_stack_init_head(&head);
    t_stack_init_node(&node1);
    t_stack_init_node(&node2);
    t_stack_init_node(&node3);
    t_stack_push(&head, &node1);
    t_stack_push(&head, &node2);
    t_stack_push(&head, &node3);
    t_stack_free(&head, free_func);
    EXPECT_EQ(3, num);
}



TEST(tstackTest, Foreach)
{
    tstack head;
    struct num_list node1, node2, node3;
    node1.num = 1;
    node2.num = 2;
    node3.num = 3;
    t_stack_init_head(&head);
    t_stack_init_node(&node1.node);
    t_stack_init_node(&node2.node);
    t_stack_init_node(&node3.node);
    t_stack_push(&head, &node1.node);
    t_stack_push(&head, &node2.node);
    t_stack_push(&head, &node3.node);

    tstack *pos;
    int i = 4;
    t_stack_foreach(pos, &head)
    {
        --i;
        EXPECT_EQ(i, T_CONTAINER_OF(pos, num_list, node)->num);
    }
}

TEST(tstackTest, Check)
{
    tstack head, node1, node2, node3;
    t_stack_init_head(&head);
    t_stack_init_node(&node1);
    t_stack_init_node(&node2);
    t_stack_init_node(&node3);
    EXPECT_TRUE(t_stack_is_empty(&head));
    EXPECT_EQ(0, t_stack_length(&head));
    t_stack_push(&head, &node1);
    EXPECT_EQ(1, t_stack_length(&head));
    t_stack_push(&head, &node2);
    t_stack_push(&head, &node3);
    EXPECT_EQ(3, t_stack_length(&head));
    t_stack_pop(&node2);
    EXPECT_FALSE(t_stack_is_empty(&head));
    EXPECT_EQ(2, t_stack_length(&head));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}

