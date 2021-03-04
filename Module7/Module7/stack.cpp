#include "stack.h"

using namespace std;

/**************************************************************************************************************
* Name: Deconstructor
* 
* Precondition: A stack object exists if it was declared
* 
* Postcondition: The stack object freed up the memory that was allocated by going through the stack and popping 
* off each item until it was empty
* 
* Description: pops off each item within the stack until the stack is empty
* 
***************************************************************************************************************/

stack::~stack()
{
	/* cout << "Inside !stack \n";*/
	while (s_top != 0)
	{
		pop();
	}
}

/**************************************************************************************************************
* Name: Pop
*
* Precondition: A stack object exists if it was initialized that has data inside it
*
* Postcondition: the item off the top of the stack was removed
*
* Description: removes the top of the stack object
*
***************************************************************************************************************/


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

/**************************************************************************************************************
* Name: Push
*
* Precondition: a stack object exists if it was initialized
*
* Postcondition: a stack_element was added to the top of the stack object
*
* Description: adds a stack_element to the top of the stack object
*
***************************************************************************************************************/


void stack::push(const stack_element& item)
{
	/*cout << "Inside push \n";*/
	stack_node* p = new stack_node;
	p->data = item;
	p->next = s_top;
	s_top = p;
}

/**************************************************************************************************************
* Name: Print
*
* Precondition: A stack object exists if it was initialized
*
* Postcondition: each linked stack_node was printed out in the stack starting with the top of the stack
*
* Description: prints out all the items contained in the stack starting at the top
*
***************************************************************************************************************/


void stack::print()
{
	/* cout << "Inside print \n";*/

	for (stack_node* p = s_top; p != 0; p = p->next)
	{
		cout << p->data << endl;
	}
}

/**************************************************************************************************************
* Name: Top
*
* Precondition: A stack object exists if it was initialized 
*
* Postcondition: the top stack_element was returned from the stack
*
* Description: returns the top stack_element of the stack
*
***************************************************************************************************************/


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

/**************************************************************************************************************
* Name: Copy Constructor
*
* Precondition: A stack object exists if it was declared
*
* Postcondition: Copies the contents of a Stack that was passed into the argument to the object
* that was initialized
*
* Description: copies the contents of a Stack to another stack object
*
***************************************************************************************************************/


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


/**************************************************************************************************************
* Name: Empty
*
* Precondition: A stack object exists if it was declared
*
* Postcondition: returned true if the stack was empty, false if it was not empty
*
* Description: returns true if the stack is empty
*
***************************************************************************************************************/

bool stack::empty()
{
	return s_top == 0;
}
