#include "utils.cpp"
#include <gtest/gtest.h>
#include <vector>

TEST(avgTest, correctness)
{
    ASSERT_EQ(2, avg({1.0, 2.0, 3.0}));
}

TEST(is_numberTest, correctness)
{
    std::vector<std::string> numbers{"5", "-5", "52.1", "-0.5"};
    std::vector<std::string> notnumbers{"a58", ""};

    for (auto x : numbers) ASSERT_EQ(1, is_number(x));
    for (auto x : notnumbers) ASSERT_EQ(0, is_number(x));
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
