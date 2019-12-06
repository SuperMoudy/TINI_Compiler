#include "scanner.h"
using namespace std;
void get_token(std::string s)
{
	ofstream out_file("output.txt");
	//ofstream out_file("output2.txt");
	//ofstream out_file("test_output.txt");
	TokenRecord token;
	bool lookahead = false;
	int state = START;
	int i = 0;
	bool reach_end_flag = false;
	char input = s[i];
	int length = s.length();

	// new update: handling comments
	int left_braces = 0;
	int right_braces = 0;

	//while (s[i] != NULL)
	while(i < length)
	{
		input = s[i];
		if (reach_end_flag == true)
		{
			if (input != ' ')
				state = DONE;
			
			i++;
		}
		switch (state)
		{


		case START:
			if (input == ' ')
				state = START;
			else if (input == '{')
			{
				state = INCOMMENT;
				left_braces++;
			}
			else if (int(input) >= int('0') && int(input) <= int('9'))
			{
				token.token_val = NUM;
				token.lexeme = input;
				token.num_val = int(input);
				state = INNUM;
			}
			else if (int(input) >= int('A') && int(input) <= int('z'))
			{
				token.token_val = ID;
				token.lexeme = input;
				state = INID;
			}
			else if (input == ':')
			{
				token.token_val = ASSIGN;
				token.lexeme = input;
				state = INASSIGN;
			}
			else
			{
				state = DONE;
				token.lexeme = input;

				if (input == '+')
					token.token_val = PLUS;

				else if (input == '-')
					token.token_val = MINUS;

				else if (input == '*')
					token.token_val = MULTIPLY;

				else if (input == '/')
					token.token_val = DIVISION;

				else if (input == '=')
					token.token_val = EQUAL;

				else if (input == '<')
					token.token_val = LESS_THAN;

				else if (input == '(')
					token.token_val = LEFT_BRACKET;

				else if (input == ')')
					token.token_val = RIGHT_BRACKET;

				else if (input == ';')
					token.token_val = SEMI_COLON;
			}
			break;

		case INCOMMENT:
			if (input == '}')
			{
				right_braces++;
				if (left_braces == right_braces)
				{
					state = START;
				}
			}
			else
				state = INCOMMENT;
			break;

		case INNUM:
			if (int(input) >= int('0') && int(input) <= int('9'))
			{
				token.lexeme += input;
				token.num_val = stoi(token.lexeme);
			}
			else
			{
				lookahead = true;
				state = DONE;
			}
			break;

		case INID:
			if (int(input) >= int('A') && int(input) <= int('z'))
			{
				token.lexeme += input;
				state = INID;
			}
			else
			{
				lookahead = true;
				state = DONE;
			}

			break;

		case INASSIGN:
			if (input == '=')
			{
				token.lexeme += input;
				state = DONE;
			}
			else
			{
				lookahead = true;
				state = DONE;
			}
			break;

		case DONE:
			state = START;
			out_file << token.lexeme << ", ";
			switch (token.token_val)
			{
			case ID:
				if (token.lexeme == "if" || token.lexeme == "else" || token.lexeme == "then" ||
					token.lexeme == "end" || token.lexeme == "repeat" || token.lexeme == "until" ||
					token.lexeme == "read" || token.lexeme == "write")
				{
					out_file << "reserved word";
				}
				else
				{
					out_file << "Identifier";
				}
				break;

			case NUM:
				out_file << "Number";
				break;

			default:
				out_file << "Symbol";
				break;


			}
			out_file << endl;

			if (lookahead == true)
			{
				i--;
				lookahead = false;
			}

			break;
		}

		if (i == (length - 1))
		{
			reach_end_flag = true;
		}
		if (state != DONE && i != (length - 1) && i != length)
			i++;

	}
	cout << "Code is scanned Successfully and output file is generated" << endl;
}