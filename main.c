#include <stdio.h>

#include "parser.h"
#include <string.h>

void Parser_Tests_Run();

int main(void) {
  
  Parser_Tests_Run();
  
  // Playground
  
  char *StringToParse = "3";

  ParserResult_t Result;
  Parser_Evaluate(StringToParse, &Result);

  if (true == Result.Success)
  {
    printf("Parser succeeded.\n");
    printf("Result: %u\n", Result.Int32Result);
    return 0;
  }
  else
  {
    printf("Parser failed.\n");
    printf("Message: %s\n", Result.Message);
    return 1;
  }
}
