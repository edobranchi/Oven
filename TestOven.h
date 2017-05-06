#ifndef TESTOVEN_H_
#define TESTOVEN_H_

#include <cxxtest/TestSuite.h>

#include "Oven.h"

class TestOven : public CxxTest::TestSuite
{
public:
    void testOven()
    {
        Oven oven;
        TS_ASSERT_EQUALS(oven.getTemp()==0, true);
        TS_ASSERT_EQUALS(oven.isOn(), false);
        TS_ASSERT_EQUALS(oven.isMicrowave(), true);
        TS_ASSERT_EQUALS(oven.isGrill(), false);
        TS_ASSERT_EQUALS(oven.isDoorOpen(), false);
    }

    void testStart()
    {
        Oven oven;
        TS_ASSERT_EQUALS(oven.start(), false);
        oven.setTemp(180.);
        TS_ASSERT_EQUALS(oven.start(), true);
    }

    void testStop()
    {
        Oven oven;
        TS_ASSERT_EQUALS(oven.stop(), false);
        oven.setTemp(180.);
        oven.start();
        TS_ASSERT_EQUALS(oven.stop(), true);
    }

    void testSetTemp()
    {
        Oven oven;
        oven.setTemp(-1);
        TS_ASSERT_EQUALS(oven.getTemp()==0, true);
        oven.setTemp(180);
        TS_ASSERT_EQUALS(oven.getTemp()==180, true);
        oven.setTemp(801);
        TS_ASSERT_EQUALS(oven.getTemp()==800, true);
    }

    void testSetDoorOpen()
    {
        Oven oven;
        oven.setDoorOpen(true);
        TS_ASSERT_EQUALS(oven.isDoorOpen(), true);
        TS_ASSERT_EQUALS(oven.start(), false);
        oven.setDoorOpen(false);
        oven.setMicrowave(true);
        oven.setTemp(180);
        TS_ASSERT_EQUALS(oven.start(), true);
        oven.setDoorOpen(true);
        TS_ASSERT_EQUALS(oven.isOn(), false);
    }

};

#endif /*TESTOVEN_H_*/
