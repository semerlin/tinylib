/**
 * Copyright 2017-2018, Huang Yang <elious.huang@gmail.com>. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#include "gtest/gtest.h"
#include "tqsort.h"

TEST(TslistTest, Sort)
{
    tchar data_char[] = {6, -2, 7, 3, -8 ,9};
    tint data_int[] = {786, 522, 367, 1183, 99898 ,27169};

    t_qsort_tchar(data_char, 0, 5);
    EXPECT_EQ(-8, data_char[0]);
    EXPECT_EQ(-2, data_char[1]);
    EXPECT_EQ(3, data_char[2]);
    EXPECT_EQ(6, data_char[3]);
    EXPECT_EQ(7, data_char[4]);
    EXPECT_EQ(9, data_char[5]);

    t_qsort_tint(data_int, 0, 5);
    EXPECT_EQ(367, data_int[0]);
    EXPECT_EQ(522, data_int[1]);
    EXPECT_EQ(786, data_int[2]);
    EXPECT_EQ(1183, data_int[3]);
    EXPECT_EQ(27169, data_int[4]);
    EXPECT_EQ(99898, data_int[5]);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}

