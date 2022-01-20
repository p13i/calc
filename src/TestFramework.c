#include "TestFramework.h"

#include <stdio.h>

#include <stdlib.h>

void TestFail(char * message) {
    printf("Assertion failed: %s\n", message);
    exit(-1);
}

void AssertTrue(bool condition, char * message) {
    if (false == condition) {
        TestFail(message);
    }
}

void AssertFalse(bool condition, char * message) {
    if (true == condition) {
        TestFail(message);
    }
}