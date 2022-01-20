#ifndef TESTFRAMEWORK_H
#define TESTFRAMEWORK_H

#include <stdbool.h>

void TestFail(char *message);
void AssertTrue(bool condition, char *message);
void AssertFalse(bool condition, char *message);

#endif // TESTFRAMEWORK_H