#include <trantor/utils/Date.h>
#include <gtest/gtest.h>
#include <string>
#include <iostream>
using namespace trantor;
TEST(Date, constructorTest)
{
    EXPECT_STREQ("1985-01-01 00:00:00",
                 trantor::Date(1985, 1, 1)
                     .toCustomedFormattedStringLocal("%Y-%m-%d %H:%M:%S")
                     .c_str());
    EXPECT_STREQ("2004-02-29 00:00:00.000000",
                 trantor::Date(2004, 2, 29)
                     .toCustomedFormattedStringLocal("%Y-%m-%d %H:%M:%S", true)
                     .c_str());
    EXPECT_STRNE("2001-02-29 00:00:00.000000",
                 trantor::Date(2001, 2, 29)
                     .toCustomedFormattedStringLocal("%Y-%m-%d %H:%M:%S", true)
                     .c_str());
    EXPECT_STREQ("2018-01-01 00:00:00.000000",
                 trantor::Date(2018, 1, 1, 12, 12, 12, 2321)
                     .roundDay()
                     .toCustomedFormattedStringLocal("%Y-%m-%d %H:%M:%S", true)
                     .c_str());
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}