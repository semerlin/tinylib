/**
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#include "gtest/gtest.h"
#include "tqueue.h"

struct num_list
{
    int num;
    tqueue node;
};

#ifdef T_ENABLE_ASSERT
TEST(TqueueTest, Death)
{
    tqueue head, node;
    EXPECT_DEATH(t_queue_init_head(NULL), "");
    EXPECT_DEATH(t_queue_init_node(NULL), "");
    EXPECT_DEATH(t_queue_append(&head, NULL), "");
    EXPECT_DEATH(t_queue_append(NULL, &node), "");
    EXPECT_DEATH(t_queue_pop(NULL), "");
    EXPECT_DEATH(t_queue_is_empty(NULL), "");
    EXPECT_DEATH(t_queue_length(NULL), "");
    EXPECT_DEATH(t_queue_free(NULL, NULL), "");
}
#endif

TEST(TqueueTest, Init)
{
    tqueue head = {NULL, NULL};
    tqueue node = {&head, &head};
    t_queue_init_head(&head);
    EXPECT_EQ(&head, head.prev);
    EXPECT_EQ(&head, head.next);
    t_queue_init_node(&node);
    EXPECT_EQ(NULL, node.prev);
    EXPECT_EQ(NULL, node.next);
}

TEST(tqueueTest, Append)
{
    tqueue head, node1, node2, node3;
    t_queue_init_head(&head);
    t_queue_init_node(&node1);
    t_queue_init_node(&node2);
    t_queue_init_node(&node3);
    t_queue_append(&head, &node1);
    t_queue_append(&head, &node2);
    t_queue_append(&head, &node3);
    EXPECT_EQ(&node2, node1.next);
    EXPECT_EQ(&head, node1.prev);
    EXPECT_EQ(&node3, node2.next);
    EXPECT_EQ(&node1, node2.prev);
    EXPECT_EQ(&head, node3.next);
    EXPECT_EQ(&node2, node3.prev);
    EXPECT_EQ(&node1, head.next);
    EXPECT_EQ(&node3, head.prev);
}

TEST(tqueueTest, Pop)
{
    tqueue head, node1, node2, node3;
    t_queue_init_head(&head);
    t_queue_init_node(&node1);
    t_queue_init_node(&node2);
    t_queue_init_node(&node3);
    t_queue_append(&head, &node1);
    t_queue_append(&head, &node2);
    t_queue_append(&head, &node3);
    t_queue_pop(&head);
    EXPECT_EQ(&node2, head.next);
    EXPECT_EQ(&node3, head.prev);
    EXPECT_EQ(&node3, node2.next);
    EXPECT_EQ(&head, node2.prev);
    EXPECT_EQ(&head, node3.next);
    EXPECT_EQ(&node2, node3.prev);
    EXPECT_EQ(NULL, node1.next);
    EXPECT_EQ(NULL, node1.prev);
}

int num = 0;
void free_func(void *args)
{
    num ++;
}

TEST(tqueueTest, Free)
{
    tqueue head, node1, node2, node3;
    t_queue_init_head(&head);
    t_queue_init_node(&node1);
    t_queue_init_node(&node2);
    t_queue_init_node(&node3);
    t_queue_append(&head, &node1);
    t_queue_append(&head, &node2);
    t_queue_append(&head, &node3);
    t_queue_free(&head, free_func);
    EXPECT_EQ(3, num);
}



TEST(tqueueTest, Foreach)
{
    tqueue head;
    struct num_list node1, node2, node3;
    node1.num = 1;
    node2.num = 2;
    node3.num = 3;
    t_queue_init_head(&head);
    t_queue_init_node(&node1.node);
    t_queue_init_node(&node2.node);
    t_queue_init_node(&node3.node);
    t_queue_append(&head, &node1.node);
    t_queue_append(&head, &node2.node);
    t_queue_append(&head, &node3.node);

    tqueue *pos;
    int i = 0;
    t_queue_foreach(pos, &head)
    {
        ++i;
        EXPECT_EQ(i, T_CONTAINER_OF(pos, num_list, node)->num);
    }
}

TEST(tqueueTest, Check)
{
    tqueue head, node1, node2, node3;
    t_queue_init_head(&head);
    t_queue_init_node(&node1);
    t_queue_init_node(&node2);
    t_queue_init_node(&node3);
    EXPECT_TRUE(t_queue_is_empty(&head));
    EXPECT_EQ(0, t_queue_length(&head));
    t_queue_append(&head, &node1);
    EXPECT_EQ(1, t_queue_length(&head));
    t_queue_append(&head, &node2);
    t_queue_append(&head, &node3);
    EXPECT_EQ(3, t_queue_length(&head));
    t_queue_pop(&node2);
    EXPECT_FALSE(t_queue_is_empty(&head));
    EXPECT_EQ(2, t_queue_length(&head));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}

