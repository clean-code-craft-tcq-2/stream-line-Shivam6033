#include "receiver.h"

void collectInputData(char input[50][20])
{
    char line[50];
    char *result;

    result = gets(line);
    int i = 0;
    while (result != NULL)
    {
        strcpy(input[i], line);
        result = gets(line);
        i++;
    }
}

void collectAmpData(char input[50][20], int ampData[50], int size)
{
    for (int i = 0; i < size; i++)
    {
        char *ampDataString = strtok(input[i], ",");
        char *ampDataValueString = strtok(ampDataString, " ");
        int ampDataValue = atoi(strtok(NULL, " "));
        ampData[i] = ampDataValue;
    }
}

void collectTempData(char input[50][20], int tempData[50], int size)
{
    for (int i = 0; i < size; i++)
    {
        char *tempDataString = strtok(input[i], ",");
        char *tempDataValueString = strtok(NULL, " ");
        int tempDataValue = atoi(strtok(NULL, " "));
        tempData[i] = tempDataValue;
    }
}

int getMinArrayValue(int arr[50], int size)
{
    int minValue = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
        }
    }
    return minValue;
}

int getMaxArrayValue(int arr[50], int size)
{
    int maxValue = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

float getSimpleMovingAverage(int arr[50], int start, int end)
{
    float sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += (float)arr[i];
    }
    return (float)(sum / 5.0);
}

int receiveDataAndProcess()
{
    char input[50][20];
    char inputCopy[50][20];
    collectInputData(input);

    int ampData[50];
    int cb = sizeof(char) * 50 * 20;
    memcpy(inputCopy, input, cb);
    collectAmpData(inputCopy, ampData, 50);

    int tempData[50];
    memcpy(inputCopy, input, cb);
    collectTempData(inputCopy, tempData, 50);

    printf("MIN AMP: %d\n", getMinArrayValue(ampData, 50));
    printf("MAX AMP: %d\n", getMaxArrayValue(ampData, 50));
    printf("SIMPLE MOVING AVG OF AMP: %f\n", getSimpleMovingAverage(ampData, 45, 50));

    printf("MIN TEMP: %d\n", getMinArrayValue(tempData, 50));
    printf("MAX TEMP: %d\n", getMaxArrayValue(tempData, 50));
    printf("SIMPLE MOVING AVG OF TEMP: %f\n", getSimpleMovingAverage(tempData, 45, 50));
}

// Uncomment this code to run as app. Commentend out since main() does not work with Catch framework for tests
/*int main(int argc, char const *argv[])
{
    receiveDataAndProcess();
    return 0;
}*/

