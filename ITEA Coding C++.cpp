#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

constexpr char numbers[] = "1234567890";
constexpr char actions[] = "+-/:*%_";
constexpr char dot_comma[] = ",.";

class Calculator
{
	double result = 0.0;
	string expression;
	stringstream convert;

	//constructor

public:

	Calculator()
	{
		cout << "Enter any exprecion, you want to calculate : ";
		getline(cin, expression);
	}

	//methods

	double calculate(char act)
	{
		double number[2] = { -1, -1 };
		int k = 0;
		char* line = new char[expression.size() + 1];
		convert.str("");
		convert.clear();
		convert << expression;
		convert >> line;

		char* token = strtok(line, actions);
		while (token && k <= 2)
		{
			for (int i = 0;; i++)
			{
				if (token[i] == '\0')
					break;
				else if (token[i] == ',')
					token[i] = '.';
			}

			convert.str("");
			convert.clear();
			convert << token;
			convert >> number[k];
			k++;
			token = strtok(NULL, actions);
		}
		
		if (number[0] != -1 && number[1] != -1)
			switch (act)
			{
			case '+':
			{
				return number[0] + number[1];
			}
			case '-':
			{
				return number[0] - number[1];
			}
			case '/':
			case ':':
			{
				return number[0] / number[1];
			}
			case '*':
			{
				return number[0] * number[1];
			}
			case'%':
			{
				return int(number[0]) % int(number[1]);
			}
			default:
				cout << "Invalid action input!" << endl;
				return 0;
			}
		else
			cout << "Invalid expression input!" << endl;
	}

	char find_action()
	{
		for (int i = 0;; i++)
		{
			if (expression[i] != '\0')
			{
				if(expression[i] == ' ')
					expression[i] = '_';
			}
			else
				break;
		}

		for (int i = 0;; i++)
		{
			if (expression[i] != '\0')
			{
				switch (expression[i])
				{
					case '+':
					{
						return '+';
					}
					case '-':
					{
						return  '-';
					}
					case '/':
					case ':':
					{
						return '/';
					}
					case '*':
					{
						return '*';
					}
					case'%':
					{
						return '%';
					}
				}
			}
			else
				break;
		}
		cout << "No action symbol found" << endl;
		exit(0);
	}
};

int main()
{
	cout << "This program calculates a simple ariphmetic (+ - / * %), two-numbered expression" << endl;
	Calculator expression;

	cout << endl << expression.calculate(expression.find_action()) << endl;
}