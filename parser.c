#include "parser.h"

#include <stdlib.h>
#include <string.h>

// ****************************************************************
// Forward declarations for module-private functions
// ****************************************************************

// Type parser functions
static bool _TryGet_int32_t(Parser_t *Parser, int32_t* ReturnValue);

// Character utility functions
static char _ThisChar(Parser_t *Parser);
static bool _HasNextChar(Parser_t *Parser);
static char _NextChar(Parser_t *Parser);

// ****************************************************************
// Module-public functions
// ****************************************************************

// Evalutes the String and places the result in Result
void Parser_Evaluate(char *String, ParserResult_t *Result)
{
  if (String == NULL || Result == NULL)
  {
    Result->Success = false;
    Result->Message = "String or Result is NULL";
    return;
  }

    uint32_t StringLength = strlen(String);

  if (0 == StringLength)
  {
      Result->Success = false;
      Result->Message = "Length of String is 0";
      return;
  }

  Parser_t Parser;
  Parser.String = String;
  Parser.StringLength = strlen(String);
  Parser.HasResult = false;
  Parser.Cursor = -1;
  Parser.Int32Result = 0;

  // Parser state variables:
  int32_t Int32Result = 0;

    bool ParseIsOkay = true;
  while (_HasNextChar(&Parser) && ParseIsOkay)
  {
    char CurrentChar = _NextChar(&Parser);

    if ('0' <= CurrentChar && CurrentChar <= '9')
    {
        int32_t IntValue;
        bool DidGetValue = _TryGet_int32_t(&Parser, &IntValue);

        if (DidGetValue)
        {
            Int32Result += IntValue;
        }
        else 
        {
            ParseIsOkay = false;
        }
    }
    else if (CurrentChar == '-')
    {
      
    }
  }

    if (ParseIsOkay)
    {
        Result->Success = true;
        Result->Message = "Successfully evalutes to int32_t value.";
        Result->Int32Result = Int32Result;
    }
    else
    {
        Result->Success = true;
        Result->Message = "Parser failed: unknown error";
        Result->Int32Result = 0; // clear it just in case
    }
    Result->Success = ParseIsOkay;

    return;
}

// Parses an int32_t into the forward positions
bool _TryGet_int32_t(Parser_t *Parser, int32_t* ReturnValue)
{
  char CurrentChar = _ThisChar(Parser);

  // Save this index for later
  int32_t ParserStartIndex = Parser->Cursor;

  // Find the length of the integer string
  uint32_t IntegerStringLength = 0;
  while ('0' <= CurrentChar && CurrentChar <= '9')
  {
    IntegerStringLength++;
  
    if (true == _HasNextChar(Parser))
    {
      CurrentChar = _NextChar(Parser);
    }
    else 
    {
      break;
    }
  }

  // Now compute the value going backwards
  uint32_t PowerMultiplier = 1;
  int32_t Int32Result = 0;
  int32_t CurrentIndex = Parser->Cursor;

  while (ParserStartIndex <= CurrentIndex)
  {
    char CharValue = Parser->String[CurrentIndex];
    int32_t IntValue = CharValue - '0';
    
    Int32Result += IntValue * PowerMultiplier;
    PowerMultiplier *= 10;

    CurrentIndex--;
  }

  *ReturnValue = Int32Result;
  return false;
}


// ****************************************************************
// Module-private functions
// ****************************************************************

char _ThisChar(Parser_t *Parser)
{
  return Parser->String[Parser->Cursor];
}

bool _HasNextChar(Parser_t *Parser)
{
  // The next char's index must be in bounds
  return (Parser->Cursor + 1) < Parser->StringLength;
}

char _NextChar(Parser_t *Parser)
{
  return Parser->String[++Parser->Cursor];
}

void _MoveBack(Parser_t *Parser)
{
  Parser->Cursor--;
}

