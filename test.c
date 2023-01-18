#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>


/* The definition of a TEST_GROUP, the name is sample */
TEST_GROUP(FirstTestGroup)
{};

/* The definition of a belonging to the TEST_GROUP TEST, the name is ret_int_success */
TEST(FirstTestGroup, FirstTest)
{
    FAIL("Fail me!");
}

/* The definition of a belonging to the TEST_GROUP TEST, the name is ret_int_failed */
TEST(FirstTestGroup, SecondTest)
{
    STRCMP_EQUAL("hello", "world");

}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}