#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <iostream>
#include <CppUTest/MemoryLeakDetectorNewMacros.h>
#include <CppUTest/MemoryLeakDetectorMallocMacros.h>
#include <CppUTest/MemoryLeakDetector.h>
#include <CppUTest/MemoryLeakWarningPlugin.h>

using namespace std;
#include "Tijdsduur.h"

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

TEST(FirstTestGroup, ThirdTest)
{
    Tijdsduur x = Tijdsduur(1, 2);
    Tijdsduur eraf = Tijdsduur(0,30);
    x.eraf(eraf);
    CHECK_EQUAL(32, x.getSeconds());
}

TEST(FirstTestGroup, FourthTest)
{
    Tijdsduur x = Tijdsduur(1, 32);
    Tijdsduur erbij = Tijdsduur(0,30);
    x.erbij(erbij);
    CHECK_EQUAL(2, x.getSeconds());
}

TEST(FirstTestGroup, FifthTest)
{
    Tijdsduur x = Tijdsduur(1, 32);
    int maal = 2;
    x.maal(maal);
    CHECK_EQUAL(4, x.getSeconds());
}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}