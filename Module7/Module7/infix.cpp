#include "stack.h"




using namespace std;


bool check_operator(string oper)
{
	if (oper == "+" || oper == "-" || oper == "*" || oper == "/")
	{
		return true;
	}
	return false;
}
bool read_operator(string oper, stack & S, bool error)
{
	string complete;
	if (oper == "+")
	{
		if (S.empty() == true)
		{
			cout << "too many operators not enough operands\n";
			error = true;
			return error;
		}

		string right = S.top();
		S.pop();
		if (S.empty() == true)
		{
			cout << "too many operators not enough operands\n";
			error = true;
			return error;
		}

		string left = S.top();
		S.pop();
		complete = "(" + left + oper + right + ")";
		S.push(complete);
		
		
		
	}

	if (oper == "-")
	{
		if (S.empty() == true)
		{
			cout << "too many operators not enough operands\n";
			error = true;
			return error;
		}

		string right = S.top();
		S.pop();

		if (S.empty() == true)
		{
			cout << "too many operators not enough operands\n";
			error = true;
			return error;
		}

		string left = S.top();
		S.pop();
		complete = "(" + left + oper + right + ")";
		S.push(complete);
	}

	if (oper == "/")
	{
		if (S.empty() == true)
		{
			cout << "too many operators not enough operands\n";
			error = true;
			return error;
		}

		string right = S.top();
		S.pop();

		if (S.empty() == true)
		{
			cout << "too many operators not enough operands\n";
			error = true;
			return error;
		}

		string left = S.top();
		S.pop();
		string complete = "(" + left + oper + right + ")";
		S.push(complete);
	}

	if (oper == "*")
	{
		if (S.empty() == true)
		{
			cout << "too many operators not enough operands\n";
			error = true;
			return error;
		}

		string right = S.top();
		S.pop();

		if (S.empty() == true)
		{
			cout << "too many operators not enough operands\n";
			error = true;
			return error;
		}

		string left = S.top();
		S.pop();
		complete = "(" + left + oper + right + ")";
		S.push(complete);
	}

	
}

/******************************************************************************************************
Name: Thomas McGuire  Z#: Z23301770
Course: Data Structures and algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: March 3, 2021  Due Time: 11:59 PM
Total Points: 25 Assignment 7: Stack program
Description: asks the user for a postfix expression as input, and it should output the corresponding fully
parenthesized infex expression. The program should also ask the user if he/she would like to
do another conversion. If so, the user should be able to enter another postfix expression; otherwise
the program should terminate. The stack is implemeneted using a singly-linked list. The driver
infix.cpp should include the definition and declaration files for the class Stack, stack.cpp, stack.h respectively.

********************************************************************************************************/



int main()
{
	string answer = "y";
	stack* S = new stack();
	while( answer == "y")
	{
		string input;
		cout << "Input postfix: \n";
		getline(cin, input);
		int lowcounter = 0;
		int left = 0;
		int right = 0;
		int size = 0;
		bool escape = false;
		bool error = false;

		if (input == "")
		{
			S->push("");
		}
		
		for (int i = 0; i < input.length(); i++)
		{

			if (input[i] != ' ')
			{

				string character = "";
				character += input[i];

				if (check_operator(character) == true)
				{
					error = read_operator(character, *S, error);
					lowcounter = 0;
				}
				else
				{
					lowcounter++;
					if (lowcounter >= 3)
					{
						cout << "too many operands and not enough operators\n";
						for (int i = 0; i < lowcounter; i++)
						{
							S->pop();
						}
						error = true;
						break;
					}
					else
					{

						S->push(character);
						size++;

						if (input.length() == 1)
						{
							string infix = "(" + S->top() + ")";
							S->pop();
							S->push(infix);
							size = 1;
						}
					}


				}
			}

		}

		if (error != true && S->empty() != true)
		{
			string top = S->top();
			S->pop();
			bool checker = S->empty();
			if (checker != true)
			{
				cout << "too many operands and not enough operators\n";
				S->~stack();
			}
			else
			{
				S->push(top);
			}

			if (lowcounter < 3 && checker == true)
			{
				S->print();
			}
		}

		cout << "Do you want to do another infix? (y/n)\n";
		getline(cin, answer);
		S->pop();

	}
	cout << "Good Bye\n";
	S->~stack();

	return 0;
}