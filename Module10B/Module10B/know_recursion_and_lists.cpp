#include <iostream>
#include <string>

using namespace std;


struct node
{
	int data;
	node* next;
};


/*************************************************************************************
Name: fun
precondition: singly linked list exists with a pinter to the front being passed
postcondition: data from the linked list is printed out
description: prints out recursively the odd numbers in the linked list
***************************************************************************************/

void fun(struct node* start)
{
	if (start == NULL)
		return;
	cout << start->data;

	if (start->next != NULL)
		fun(start->next->next);
	cout << start->data;
};


/*************************************************************************************
Name: add_back
precondition: a front node and back node and a integer are passed into this function to create a linked list
postcondition: adds a node onto a created list or creates a list if the front does not point to a location
description: assigns the front and back of the linked list and creates a new node to add the new integer to the list.
***************************************************************************************/

void add_back(node* &front, node* &back, int num)
{

	node* p;
	p = new node;
	p->data = num;
	p->next = NULL;

	if (front == NULL)
	{
		front = p;
		back = p;
	}

	else
	{
		back->next = p;
		back = back->next;
	}


}


/******************************************************************************************************
Name: Thomas McGuire  Z#: Z23301770
Course: Data Structures and algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: March 29, 2021  Due Time: 11:59 PM
Total Points: 25 Assignment 10B: "fun recursion" program
Description: creates a singly linked list recursively that prints out the odd integers recursively in this scenario. 

********************************************************************************************************/

int main()
{
	node* front = 0;
	node* back = 0;

	for (int i = 1; i <= 6; i++)
	{
		add_back(front, back, i);
	}

	fun(front);
	return 0;
}