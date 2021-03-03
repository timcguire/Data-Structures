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
void read_operator(string oper, stack & S)
{
	string complete;
	if (oper == "+")
	{
		string right = S.top();
		cout << "right: " << right << "\n";
		S.pop();
		string left = S.top();
		cout << "left: " << left << "\n";
		S.pop();
		complete = "(" + left + oper + right + ")";
		S.push(complete);
		
		
		
	}

	if (oper == "-")
	{
		string right = S.top();
		S.pop();
		string left = S.top();
		S.pop();
		complete = "(" + left + oper + right + ")";
		S.push(complete);
	}

	if (oper == "/")
	{
		string right = S.top();
		S.pop();
		string left = S.top();
		S.pop();
		string complete = "(" + left + oper + right + ")";
		S.push(complete);
	}

	if (oper == "*")
	{
		string right = S.top();
		S.pop();
		string left = S.top();
		S.pop();
		complete = "(" + left + oper + right + ")";
		S.push(complete);
	}

	
}


int main()
{
	stack* S = new stack();

	string input;
	cout << "Input postfix: \n";
	getline(cin, input);
	int lowcounter = 0;
	int left = 0;
	int right = 0;
	
	for (int i = 0; i < input.length(); i++)
	{
		
		if (input[i] != ' ')
		{
			
			string character = "";
			character += input[i];

			if (check_operator(character) == true)
			{
				 read_operator(character, *S);
				 lowcounter = 0;
			}
			else
			{
				lowcounter++;
				if (lowcounter >= 3)
				{
					cout << "too many operandsand not enough operators\n";
					break;
				}
				else
				{

					S->push(character);
				}
				
				
			}
		}
		
	}

	if (lowcounter < 3)
	{
		S->print();
	}
}