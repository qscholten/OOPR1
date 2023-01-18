#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <iostream>
#include <CppUTest/MemoryLeakDetectorNewMacros.h>
#include <CppUTest/MemoryLeakDetectorMallocMacros.h>
#include <CppUTest/MemoryLeakDetector.h>
#include <CppUTest/MemoryLeakWarningPlugin.h>

using namespace std;
#include "FrontBoek.h"

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

TEST_GROUP(boekengroep) 
{};

TEST(boekengroep, front) 
{
    FrontBoek fb1("L&B", "lab");
    STRCMP_EQUAL("L&B", fb1.naamSchrijver().c_str());
}

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
    FrontBoek fb2("Kwik", "Titel");
    string schrijver = fb2.naamSchrijver();
    fb2.verhoogSchrijver();
    schrijver = fb2.naamSchrijver();
    STRCMP_EQUAL("Kwik1", schrijver.c_str());
}

TEST(FirstTestGroup, FourthTest)
{
    FrontBoek fb3("Kwik", "Titel");
    FrontBoek fb4 = *fb3.maakKopie();
    CHECK(true);
    //CHECK(MemoryLeakWarningPlugin::areNewDeleteOverloaded());
}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    FrontBoek fb2("L&B", "lab");
    return 0;
}