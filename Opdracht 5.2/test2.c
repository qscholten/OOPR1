#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <iostream>
#include <CppUTest/MemoryLeakDetectorNewMacros.h>
#include <CppUTest/MemoryLeakDetectorMallocMacros.h>
#include <CppUTest/MemoryLeakDetector.h>
#include <CppUTest/MemoryLeakWarningPlugin.h>

using namespace std;
#include "Logled.h"
#include <unistd.h>

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

TEST(FirstTestGroup, FirstTest)
{
    FAIL("Fail me!");
}

TEST(FirstTestGroup, SecondTest)
{
    STRCMP_EQUAL("helloworld", "helloworld");
}

TEST(FirstTestGroup, FourthTest)
{
    RockPi pi(20208294);
    Logled led(pi, 134, "rood", "Qing Scholten", 3);
    led.zetAan();
    sleep(1);
    led.zetUit();
    CHECK_EQUAL(2, led.TijdOver());
}

TEST(FirstTestGroup, FifthTest) {
    RockPi pi(20208294);
    Logled led(pi, 134, "rood", "Qing Scholten", 3);
    CHECK_EQUAL("Qing Scholten", led.deEigenaar());
}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}