#include <iomanip>
#include <string>


using namespace std;


class string_class
{
private: string current_string;

public: 
	string_class(); //default constructor
	string_class(string object); //explicit value constructor, passed a string and initializes the object with that string
	bool palindrome(); //returns true if palindrome, false otherwise
	void replace_all(string old_substring, string new_substring); //accepts two arguments; the function will replace each occurence of "old_substring with "new_substring" in the current_string"
	string getString();
	int find_position(string current_string, string find, int counter);
	friend ostream& operator<<(ostream& out, string_class& object); //overloaded insertion operator with chaining to print the contents of a string_class object's "current_string"
	






};
