#include <iostream>
#include<string.h>
#include <fstream>
#include "scanner.h"
using namespace std;
int main(void)
{
	string x;
	string a;
	ifstream my_prog;
	my_prog.open("Tiny_program.txt");
	//my_prog.open("test2_parser.txt");
	//my_prog.open("test_input.txt");
	if (my_prog.is_open())
		while (!my_prog.eof())
		{
			getline(my_prog, a);
			x += " ";
			x += a;
		}
	get_token(x);
	system("pause");
}
