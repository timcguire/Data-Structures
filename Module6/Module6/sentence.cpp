#include "sentence.h"


using namespace std;




/*************************************************************************************
Name: default constructor
precondition: no variables have been initialized and nothing has been called
postcondition: the default constructor has been called and front and back have been initialized 
with NULL
description: the default constructor that will initialize the state variables
***************************************************************************************/


sentence::sentence()
{
	this->front = NULL;
	this->back = NULL;
}


/*************************************************************************************
Name: explicit value constructor
precondition: no variables have been initialized and nothing has been called
postcondition: a string was passed into the constructor and a sentence was created, intializing 
the front and back word variables
description: the explicit-value constructor that will initialize the state variables
***************************************************************************************/

sentence::sentence(const string& s)
{
	int length = s.length();

	string temp = "";
	word* added;
	int current = 0;
	int before = 0;

	if (s.length() == 0)
	{
		added = new word();
		added->term = s;
		added->next = NULL;
		this->front = added;
		this->back = added;
	}

	current = s.find(" ");

	while (current != -1)
	{
		added = new word();
		if (this->front == NULL) {
			added->next = NULL;
			this->front = added;
			this->back = added;
		}
		else {
			this->back->next = added;
			this->back = added;
		}
		if (current == before)
		{
			// Adding only a space
			added->term = " ";


		}
		else
		{
			//there is a word and a space
			//an added word already setup
			added->term = s.substr(before, current - before);


			// creat new word record for the space and add it to the sentence
			added = new word();
			added->term = " ";
			this->back->next = added;
			this->back = added;


		}
		before = current + 1;
		current = s.find(" ", before);
	}

	temp = s.substr(before, current - before);
	if (temp.length() > 0)
	{
		added = new word();

		// this compound if is need if you have a string of 1 word and no spaces like: "ThisString"
		if (front == NULL) {
			added->next = NULL;
			added->term = s;
			this->front = added;
			this->back = added;
		}
		else 
		{
			added->term = s.substr(before, current - before);
			this->back->next = added;
			this->back = added;
		}
	}
}

/*************************************************************************************
Name: copy constructor
precondition: a sentence exists outside of this object that will be passed in to intialize the object
postcondition: this->sentence object was intializied with the sentence that was passed into the copy
constructor, the front and back word fields were intialized
description: copies the sentence object passed into this function to the current sentence object
***************************************************************************************/

sentence::sentence(const sentence& org)
{
	

	
	word* ptr = org.front;
	word* added = new word;

	this->front = added;
	this->back = NULL;

	while(ptr != NULL)
	{
		added->term = ptr->term;
		added->next = NULL;
		if (this->back != NULL)
			this->back->next = added;
		this->back = added;

		ptr = ptr->next;
		added = new word;

	} 
	delete added;
}

/*************************************************************************************
Name: deconstructor
precondition: a setnence object exists that will have its memory deallocated and deleted if this function is called
postcondition: the current sentence object was destroyed and the memory allocated was freed up
description: //Destructor: The destructor will de-allocate all memory allocated for the word.
***************************************************************************************/


sentence::~sentence()
{
	cout << "Destructor has been called\n";
	while (front != 0)
	{
		word* p = front;
		front = front->next;
		delete p;
	}


}

/*************************************************************************************
Name: length()
precondition: there is a sentence object created with a front and back word intialized
postcondition: the sentence object was gone through and the length of each word was added to the total length of the sentence
description: //Destructor: function that gives the length of the sentence object
***************************************************************************************/

int sentence::length()
{
	int length = 0;
	word* ptr = new word();
	ptr = this->front;

	while (ptr != NULL)
	{
		string s = ptr->term;
		int strlen = s.length();
		length += strlen;
		ptr = ptr->next;
	}

	return length;
}

/*************************************************************************************
Name: add_back
precondition: a sentence object has been intialized with both the front and back wards intialized
postcondition: a word object was added on to the back of the current sentence object and the back word within the sentence
was changed to point to the added word
description: adds a word object onto the back of the current sentence object
***************************************************************************************/

void sentence::add_back(string& s)
{
	word* oldlast = new word();
	word* ptr = new word();
	oldlast = this->back;
	oldlast->next = ptr;
	ptr->term = s;
	ptr->next = NULL;
	this->back = ptr;
}

/*************************************************************************************
Name: operator<<
precondition: a sentence object exists that will be passed into this function
postcondition: the sentence object was sent to the ostream out and the << was overloaded to print out the sentence
description: Overload the insertion operator as a friend function with chaining to print a word A
***************************************************************************************/

ostream& operator<<(ostream& out, const sentence& org)
{
	word* ptr = org.front;

	while (ptr != NULL)
	{
		out << ptr->term;
		ptr = ptr->next;
	}

	return out;
}

/*************************************************************************************
Name: operator=
precondition: a sentence object exists that has been initalized 
postcondition: the = operator was overloaded in order to take a string and create a sentence out of it which is assigned to the current sentence object
description: Overload the assignment operator as a member function to take a 
	//								//string (C-style or C++ string, just be consistent in your implementation) as an argument and 
	//								//assigns its value to A, the current object;
***************************************************************************************/


void sentence::operator=(const string& s)
{
	while (front != 0)
	{
		word* p = front;
		front = front->next;
		delete p;
	}


	sentence* temp = new sentence(s);
		
	this->front = temp->front;
	this->back = temp->back;
}

/*************************************************************************************
Name: operator=
precondition: a sentence object exists that has been initalized 
postcondition: the = operator was overloaded with chaining to take a sentence object and assign it to the current sentence object
description: = operator that was overloaded with chaining
***************************************************************************************/

sentence& sentence::operator=(const sentence& w)
{
	while (front != 0)
	{
		word* p = front;
		front = front->next;
		delete p;
	}


	sentence* temp = new sentence(w);

	this->front = temp->front;
	this->back = temp->back;

	return *this;
}

/*************************************************************************************
Name: operator+
precondition: a sentence object exists that has been initalized
postcondition: the + operator was overloaded to add sentences together
description: //Overload the ‘+” operator as a member function without chaining to add word B 
	//				 //(adds the set of symbols that makep B's linked list to the back of A's linked list) to the back of word A; 
	//				 //remember A is the current object;
***************************************************************************************/

void sentence::operator+(sentence& B)
{
	
	sentence* tmp = new sentence(B);

	if (this->back == NULL)
	{
		this->front = tmp->front;
		this->back = tmp->back;
	}
	else
	{
		this->back->next = tmp->front;
		this->back = tmp->back;
	}
	

	/*
	while (A != NULL || ptr != NULL)
	{
		word* added = new word();
		added->term = ptr->term;
		added->next = ptr->next;
		A->next = added;
		A = A->next;
		ptr = ptr->next;
	}
	*/
   //	this->back = B.back;
}

/*************************************************************************************
Name: isEqual
precondition: a sentence object exists that has been initalized with a front word and a back word
postcondition: two sentence objects were compared word by word to see if they were the same sentences
description: returns a 0 if the sentences are equal or a 1 if they are not
***************************************************************************************/

bool sentence::isEqual(sentence& B)
{
	word* ptr = B.front;
	word* A = this->front;
	bool equal = true;

	if (this->length() < B.length() || B.length() < this->length())
	{
		return false;
	}

	while (A != NULL)
	{
		
		if (A->term != ptr->term)
		{
			equal = false;
			break;
		}
			ptr = ptr->next;
			A = A->next;
	}

	return equal;
}

/*************************************************************************************
Name: remove
precondition: a sentence object exists that has been initalized with a front word and a back word
postcondition: if the string was contained within the sentence, it was removed and the addresses to the word before and the word after the word removed ->next addresses were adjusted
description: Deletes the first occurrence of the string s from the list A;
***************************************************************************************/


void sentence::remove(const string& s)
{
	word* temp = this->front;
	word* previous = this->front;

	if (temp->term == s)
	{
		cout << "came in here\n" << "word was: " << temp->term << "\n";
		this->front = front->next;
		delete temp;
	}

	else
	{

		while (temp != NULL)
		{
			if (temp->term == s)
			{
				if (temp == this->back)
				{
					cout << "word was found at end of sentence\n" << "word was: " << temp->term << "\n";
					this->back = previous;
					previous->next = NULL;
					delete temp;
					return;
				}
				else
				{
					cout << "word was found somewhere in between\n" << "word was: " << temp->term << "\n";
					previous->next = temp->next;
					delete temp;
					return;
				}
			}

			
				previous = temp;
				temp = temp->next;
			
		}
	}
}