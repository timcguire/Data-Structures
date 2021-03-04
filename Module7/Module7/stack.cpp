#include "stack.h"

using namespace std;

stack::~stack()
{
	/* cout << "Inside !stack \n";*/
	while (s_top != 0)
	{
		pop();
	}
}

void stack::pop()
{
	/*cout << "Inside pop \n";*/
	stack_node* p;

	if (s_top != 0)
	{
		p = s_top;
		s_top = s_top->next;
		delete p;
	}
}



void stack::push(const stack_element& item)
{
	/*cout << "Inside push \n";*/
	stack_node* p = new stack_node;
	p->data = item;
	p->next = s_top;
	s_top = p;
}

void stack::print()
{
	/* cout << "Inside print \n";*/

	for (stack_node* p = s_top; p != 0; p = p->next)
	{
		cout << p->data << endl;
	}
}

stack_element stack::top()
{
	/* cout << "Inside top \n";*/

	if (s_top == 0)
	{
		exit(1);
	}
	else
	{
		return s_top->data;
	}
}

stack::stack(const stack& Org)
{
	/*cout << "Inside the Copy Constructor\n"*/

	(*this).s_top = 0;

	stack temp;
	stack_node* p = Org.s_top;
	while (p != 0)
	{
		(*this).push(p->data);
		p = p->next;
	}
}

bool stack::empty()
{
	return s_top == 0;
}
/*
int main()
{
	stack S;

	S.push("a");
	S.push("b");
	S.push("c");
	S.push("d");
	S.push("e");
	S.push("f");
	S.push("g");
	S.print();

	cout << endl << endl;
	stack Y = S;
	Y.print();

	return 0;
}*/