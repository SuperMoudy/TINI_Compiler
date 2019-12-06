#pragma once
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#define START		100
#define INCOMMENT	101
#define INNUM		102
#define INID		103
#define INASSIGN	104
#define DONE		105

typedef enum
{
	IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE, //RESERVED WORD
	PLUS, MINUS, MULTIPLY, DIVISION, EQUAL, LESS_THAN, 
	LEFT_BRACKET, RIGHT_BRACKET, SEMI_COLON, ASSIGN, 
	NUM, ID
}TokenType;

typedef struct
{
	TokenType token_val;
	std::string lexeme;
	int num_val;
}TokenRecord;

void get_token(std::string s);