#include <ostream>
#include <iostream>
#include "string_class.h"


using namespace std;

/**************************************************************************************
Name: default constructor

Precondition: no objects have been created or initialized, when this function is called, 
no arguments will be passed into it

Postcondition: a string_class object has been initialized by a default constructor, the private data
current_string was intialized with the value ""

Description: default constructor that initializes a string_class object with the default 
for the current_string value = ""

***************************************************************************************/

string_class::string_class()
{
	this->current_string = "";
}

/**************************************************************************************
Name: explicit value constructor

Precondition: no string_class object has been initialized, when this function is called 
it will intialize a string_class object with the argument passed

Postcondition: a string_class object was intialized with the passed argument being assigned
to the private data current_string

Description: creates a sting_class object that passes a string as an argument to be initalized 
into the object's private data current_string

***************************************************************************************/

string_class::string_class(string current_string)
{
	this->current_string = current_string;
}

/**************************************************************************************
Name: palindrome

Precondition: a string_class object has been created that contains a private data current_string

Postcondition: this function was called and the private data string called current_string 
was accessed to see if it was a palindrome or not. if it was, a boolean value of true was returned,
if it was not, a boolean value of false was returned

Description: checks to see if the string_class object has a palindrome in it or not and returns a boolean 
value of true if it does and a boolean value of false if ti does not

***************************************************************************************/

bool string_class::palindrome()
{
	int strlen = this->current_string.length() - 1;
	int begin = 0;
	string check = this->current_string;

	
	while (strlen >= 0)
	{
		if (toupper(check[strlen]) == toupper(check[begin]))
		{
			strlen--;
			begin++;
		}
		else
		{
			return false;
		}
	}
	

	return true;
}



/**************************************************************************************
Name: find position

Precondition: a string_class object exists with a private string

Postcondition: takes two string arguments and an int argument and returns the substring initial position within the 
current_string

Description: returns the position of old_string within current_string

***************************************************************************************/

int string_class::find_position(string current_string, string find, int counter)
{
	int strlen = current_string.length();
	int oldlen = find.length();
	bool there = true;
	int position = -1;

	for (int i = counter; i < strlen - oldlen + 1; i++)
	{
		for (int j = 0; j < oldlen; j++)
		{
			if (current_string[i + j] != find[j])
			{
				there = false;
				break;
			}

		}
		if (there == true)
		{
			position = i;
			break;
		}


		there = true;
	}

	return position;

}

/**************************************************************************************
Name: Replace All

Precondition: a string_class object exists with a private data string current_string.
when this function is called two strings will be passed as arguments

Postcondition: the private string current_string was altered within the string_class object based 
on the two string arguments passed into the replace_all(function)

Description: replaces all instances of the old_string with the new_string in the private data 
string current_string in the string_class object

***************************************************************************************/

void string_class::replace_all(string old_string, string new_string)
{
	int strlen = this->current_string.length();
	int oldlen = old_string.length();
	int newlen = new_string.length();
	string temp = this->current_string;
	int counter = 0;
	int position = find_position(temp, old_string, counter);

	if (strlen < oldlen)
	{
		return;
	}

	if (this->current_string == "")
	{
		return;
	}

	while (position != -1)
	{

		temp.erase(position, oldlen);
		temp.insert(position, new_string);
		counter++;
		position = find_position(temp, old_string, counter);
	}

	this->current_string = temp;
	
}

/**************************************************************************************
Name: get string

Precondition: a string_class object exists with a private data string called current_string

Postcondition: the string within the string_class object was returned

Description: returns the string within a string_class object

***************************************************************************************/

string string_class::getString()
{
	return this->current_string;
}

/**************************************************************************************
Name:overloadded insertion overator

Precondition:a string_object exists with a private string current_string

Postcondition: the private string within the string_class object is put into the ostream& out

Description: inserts the string from the string_class object into the ostream& out and returns out

***************************************************************************************/

ostream& operator<<(ostream& out, string_class& object)
{
	out << object.getString();

	return out;
}
