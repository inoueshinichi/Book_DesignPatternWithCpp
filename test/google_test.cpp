
#include "gtest/gtest.h"

namespace 
{
    class DesignPatternTest : public ::testing::Test {};

    TEST_F(DesignPatternTest, TestCheck)
    {
        EXPECT_EQ(1.0, 1.0);
    }
}

int main(int argc, char** argv)
{
    return 0;
}