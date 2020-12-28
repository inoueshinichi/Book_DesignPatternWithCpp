
#include <gtest/gtest.h>
#include <gmock/gmock.h>

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
    // ::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}