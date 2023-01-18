#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <iostream>

using namespace std;


/* The definition of a TEST_GROUP, the name is sample */
TEST_GROUP(FirstTestGroup)
{
    void setup()
    {
        /* This is run before each TEST */
        cout<<"Voor de test"<<endl;
    }

    void teardown()
    {
        /* This is run after each TEST */
        cout<<"Na de test"<<endl;
    }
};

/* The definition of a belonging to the TEST_GROUP TEST, the name is ret_int_success */
TEST(FirstTestGroup, FirstTest)
{
    FAIL("Fail me!");
}

/* The definition of a belonging to the TEST_GROUP TEST, the name is ret_int_failed */
TEST(FirstTestGroup, SecondTest)
{
    STRCMP_EQUAL("hello world", "hello world");

}

TEST(FirstTestGroup, ThirdTest)
{
    CHECK_EQUAL(10, 30);
}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}