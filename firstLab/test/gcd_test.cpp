#include "gcd.h"
#include "/opt/homebrew/include/gtest/gtest.h"

TEST(GCDTest, OneZero) {
    EXPECT_EQ(gcd(0, 5), 5);
    EXPECT_EQ(gcd(7, 0), 7);
}

TEST(GCDTest, NormalCases) {
    EXPECT_EQ(gcd(6, 9), 3);
    EXPECT_EQ(gcd(10, 5), 5);
    EXPECT_EQ(gcd(17, 13), 1);
}

TEST(GCDTest, BothZero) {
    EXPECT_EQ(gcd(0, 0), -1);
}

TEST(GCDTest, SameNumbers) {
    EXPECT_EQ(gcd(7, 7), 7);
}

TEST(GCDTest, LargeNumbers) {
    EXPECT_EQ(gcd(123456, 789012), 12);
}

