#include "TestFramework.h"
#include "parser.h"
#include <stdio.h>

void Parser_Tests_Run_Basics() 
{
  {
    ParserResult_t Result;
    Parser_Evaluate("", &Result);

    AssertTrue(Result.Success == false, "");
    AssertTrue(Result.Message != NULL, "");
  }
  
  {
    ParserResult_t Result;
    Parser_Evaluate("0", &Result);

    AssertTrue(Result.Success == true, "");
    AssertTrue(Result.Int32Result == 0, "");
  }
  
  {
    ParserResult_t Result;
    Parser_Evaluate("1", &Result);

    AssertTrue(Result.Success == true, "");
    AssertTrue(Result.Int32Result == 1, "");
  }

  {
    ParserResult_t Result;
    Parser_Evaluate("2", &Result);

    AssertTrue(Result.Success == true, "");
    AssertTrue(Result.Int32Result == 2, "");
  }
  
  {
    ParserResult_t Result;
    Parser_Evaluate("10", &Result);

    AssertTrue(Result.Success == true, "");
    AssertTrue(Result.Int32Result == 10, "");
  }

  {
    ParserResult_t Result;
    Parser_Evaluate("12345", &Result);

    AssertTrue(Result.Success == true, "");
    AssertTrue(Result.Int32Result == 12345, "");
  }
}

void Parser_Tests_Run()
{
  // Test basics

  Parser_Tests_Run_Basics();

}