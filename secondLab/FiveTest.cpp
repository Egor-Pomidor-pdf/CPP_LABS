#include <gtest/gtest.h>
#include "Five.h"

TEST(FiveTest, DefaultConstructor) {
    Five num;
    SUCCEED();
}

TEST(FiveTest, StringConstructor) {
    Five num("123");
    SUCCEED();
}

TEST(FiveTest, CopyConstructor) {
    Five a("12");
    Five b(a);
    SUCCEED();
}

TEST(FiveTest, Addition) {
    Five a("12");
    Five b("3");
    Five result = a.sum(b);
    SUCCEED();
}

TEST(FiveTest, Subtraction) {
    Five a("20");
    Five b("3");
    Five result = a.sub(b);
    SUCCEED();
}

TEST(FiveTest, AdditionAssignment) {
    Five a("12");
    Five b("3");
    a.sumAs(b);
    SUCCEED();
}

TEST(FiveTest, SubtractionAssignment) {
    Five a("20");
    Five b("3");
    a.subAs(b);
    SUCCEED();
}

TEST(FiveTest, LessThan) {
    Five a("12");
    Five b("20");
    EXPECT_TRUE(a.lt(b)); 
}

TEST(FiveTest, Equal) {
    Five a("12");
    Five b("12");
    EXPECT_TRUE(a.eq(b));
}

TEST(FiveTest, GreaterThan) {
    Five a("20");
    Five b("12");
    EXPECT_TRUE(a.mt(b));  
}

TEST(FiveTest, SubtractionException) {
    Five a("3");
    Five b("12");
    EXPECT_THROW(a.sub(b), std::underflow_error);  
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}