#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void collectInputData(char input[50][20]);

void collectAmpData(char input[50][20], int ampData[50], int size);

void collectTempData(char input[50][20], int tempData[50], int size);

int getMinArrayValue(int arr[50], int size);

int getMaxArrayValue(int arr[50], int size);

float getSimpleMovingAverage(int arr[50], int start, int end);

