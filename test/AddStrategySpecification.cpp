#include <gtest/gtest.h>

#include <limits.h>

#include "AddStrategy.h"

namespace {

class AddStrategySpecification : public ::testing::Test {
};


TEST(AddStrategySpecification,
    ShouldAddNumbers)
{
    AddStrategy *add = new AddStrategy();
    ASSERT_TRUE(add != NULL);
    int result = add->execute(4, 2);
    ASSERT_EQ(result, 6);
    delete add;
}

TEST(AddStrategySpecification,
    ShouldAddBigNumbers)
{
    AddStrategy *add = new AddStrategy();

    ASSERT_TRUE(add != NULL);
    ASSERT_TRUE(INT_MAX == 2147483647);

    int result = add->execute(2147483647, 2147483647);
    ASSERT_EQ(result, 4294967294UL);
    delete add;
}

TEST(AddStrategySpecification,
    ShouldAddNegativeNumbers)
{
    AddStrategy *add = new AddStrategy();
    ASSERT_TRUE(add != NULL);
    int result = add->execute(-10, -5);
    ASSERT_EQ(result, -15);
    delete add;
}

TEST(AddStrategySpecification,
    ShouldAddNegativeAndPositiveNumbers)
{
    AddStrategy *add = new AddStrategy();
    ASSERT_TRUE(add != NULL);
    int result = add->execute(-10, 20);
    ASSERT_EQ(result, 10);
    delete add;
}

TEST(AddStrategySpecification,
    ShouldAddBigNegativeNumbers)
{
    AddStrategy *add = new AddStrategy();
    ASSERT_TRUE(add != NULL);
    int result = add->execute(INT_MIN, INT_MAX);
    ASSERT_EQ(result, -1);
    delete add;
}

}
