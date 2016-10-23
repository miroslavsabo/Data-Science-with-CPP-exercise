#include "utils.cpp"
#include <gtest/gtest.h>
#include <vector>

TEST(avgTest, correctness)
{
    std::vector<double> v{1.0, 2.0, 3.0};
    ASSERT_EQ(2, avg(v));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
