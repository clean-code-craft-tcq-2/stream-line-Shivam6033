#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "../test/catch.hpp"
#include "receiver.h"

SCENARIO("check amp data array is populated with correct data for given input array")
{
    GIVEN("an input array of format")
    {
        char input[4][20] = {"Amps: 4, Temp: 83", "Amps: 2, Temp: 77", "Amps: 10, Temp: 52", "Amps: 8, Temp: 96"};
        int ampData[4];

        WHEN("collectAmpData() is called with input array and amp array")
        {
            collectAmpData(input, ampData, 4);
            THEN("amp array is set with amp values from input")
            {
                REQUIRE(ampData[0] == 4);
                REQUIRE(ampData[1] == 2);
                REQUIRE(ampData[2] == 10);
                REQUIRE(ampData[3] == 8);
            }
        }
    }
}

SCENARIO("check temp data array is populated with correct data for given input array")
{
    GIVEN("an input array of format")
    {
        char input[4][20] = {"Amps: 4, Temp: 83", "Amps: 2, Temp: 77", "Amps: 10, Temp: 52", "Amps: 8, Temp: 96"};
        int tempData[4];

        WHEN("collectTempData() is called with input array and temp array")
        {
            collectTempData(input, tempData, 4);
            THEN("temp array is set with temp values from input")
            {
                REQUIRE(tempData[0] == 83);
                REQUIRE(tempData[1] == 77);
                REQUIRE(tempData[2] == 52);
                REQUIRE(tempData[3] == 96);
            }
        }
    }
}

SCENARIO("check min value in array is obtained")
{
    GIVEN("an array of integers")
    {
        int arr[5] = {10, 4, 23, 13, 2};

        WHEN("getMinArrayValue() is called with array")
        {
            int min = getMinArrayValue(arr, 5);
            THEN("minimum value from array is returned")
            {
                REQUIRE(min == 2);
            }
        }
    }
}

SCENARIO("check max value in array is obtained")
{
    GIVEN("an array of integers")
    {
        int arr[5] = {10, 4, 23, 13, 2};

        WHEN("getMaxArrayValue() is called with array")
        {
            int max = getMaxArrayValue(arr, 5);
            THEN("maximum value from array is returned")
            {
                REQUIRE(max == 23);
            }
        }
    }
}

SCENARIO("check average of values from array for given start and end position is returned")
{
    GIVEN("an array of integers")
    {
        int arr[5] = {10, 4, 23, 13, 2};

        WHEN("getSimpleMovingAverage() is called with start and end positions")
        {
            float avg = getSimpleMovingAverage(arr, 1, 5);
            THEN("average value from array for given range is returned")
            {
                REQUIRE(avg == 8.4f);
            }
        }
    }
}
