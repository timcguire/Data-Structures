
#include "state.h"
#include <iomanip>  //need to use formatting manipulators


/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Default Constructor
Pre-Conditon: The count, capacity, and the dynamic array (pop_DB) have not been initialized.
Post-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
Description:  The function initiailizes the state (private data) of the class state_class. It reads the data stored in the datafile "census2020_data.txt"
			  into the dynamic array, pop_DB.  Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.  If pop_DB become full,
			  double_size is called, which doubles the capacity of pop_DB.

**********************************************************************************************************************************************************/
state_class::state_class()
{
	//intially count, capacity, and pop_DB are initialized with the following values:
	count = 0;
	capacity = 5;
	pop_DB = new population_record[capacity];

	population_record temp;
	string stemp;
	double itemp;
	ifstream myfile("census2020_data.txt");

	
	//while not at the end of myfile
	while (!myfile.eof())
	{
		//get a line of the file
		getline(myfile, stemp);

		
		if (this->Is_Full() == false)
		{
			string separate = stemp;
			string name;
			int seplength = separate.length();
			string number;

			//loop to parse through the line and determine number or string
			for (int i = 0; i < seplength; i++)
			{
				//if the char withhin the string at location i is a digit
				if (isdigit(separate[i]))
				{
					//pushes the char into a separate string called number
					number.push_back(separate[i]);
				}
				//else if char within the string at location i is a letter or space
				else if ((separate[i] >= 'A' && separate[i] <= 'Z') || (separate[i] >= 'a' && separate[i] <= 'z') || separate[i] == ' ')
				{
					//push the char into a string called name
					name.push_back(separate[i]);
				}
			}

			name = name.erase(name.length() - 1);
			
			itemp = stod(number);
			
			//assigns a state name and population size
			pop_DB[count].state_name = name;
			pop_DB[count].population = itemp;
			//increases the count
			count++;
		}
		else
		{
			//array was full incrase the capacity by calling double_size();
			double_size();
			
			string separate = stemp;
			string name;
			int seplength = separate.length();
			string number;

			for (int i = 0; i < seplength; i++)
			{
				if (isdigit(separate[i]))
				{
					number.push_back(separate[i]);
				}
				
				else if ((separate[i] >= 'A' && separate[i] <= 'Z') || (separate[i] >= 'a' && separate[i] <= 'z') || separate[i] == ' ')
				{
					name.push_back(separate[i]);
				}
			}

			name = name.erase(name.length() - 1);
			

			itemp = stod(number);
		
			pop_DB[count].state_name = name;
			pop_DB[count].population = itemp;
			count++;
		}
	}
}

/******************************************************************************************************************************************************
Name:Copy Constructor
Pre-Condition: Before this function is called there exists a state_class that is going to be copied
Post-Condition: After this Function is called, the state_class that existed prior to the function call is copied into a new state_class, copying over the count, capacity, and pop_DB into the new state_class while still keeping the old one
Description: takes the private fields saved in the original state_class and copies them over to the new state_class
******************************************************************************************************************************************************/
state_class::state_class(const state_class& org)
{
	count = org.count;
	capacity = org.capacity;
	pop_DB = org.pop_DB;
}

/******************************************************************************************************************************************************
Name:Deconstructor
Pre-Condition: a state_class exists with a dynamic array that has memory allocated to it
Post-Condition after this function executes, the memory for the dynamic array is deleted and deallocated
Description: pop_DB is cleared of any memory alocated and deleted 
******************************************************************************************************************************************************/
state_class::~state_class()
{
	delete[] pop_DB;

}

/******************************************************************************************************************************************************
Name: Double Size
Pre-Condition: a full dynamic array where count contains how many objects are in the array and capacity contains how much space has been allocated to the array
Post-Condition the capacity has been doubled as a field and the memory allocated for the dynamic array has been doubled
Description: This function doubles the size of the dynamic array
******************************************************************************************************************************************************/
void state_class::double_size()
{
	int length = capacity;
	capacity = capacity * 2;
	population_record* temp = new population_record[capacity];

	for (int i = 0; i < length; i++)
	{
		temp[i] = pop_DB[i];
	}

	pop_DB = NULL;

	pop_DB = new population_record[capacity];
	for (int i = 0; i < length; i++)
	{
		pop_DB[i] = temp[i];
	}

	delete[] temp;

}

/******************************************************************************************************************************************************
Name: overload operator
Pre-Condition: a state class dynamic array exists with population records in it, there is a set count and a set capacity, a population record will be passed into
method called r
Post-Condition: the population_record r that was passed into this method was added to the dynamic array of population records where space was available
Description:adds a population record to the end of the array
******************************************************************************************************************************************************/
void state_class::operator+(const population_record& r)
{
	if (!Is_Full())
	{
		pop_DB[count].state_name = r.state_name;
		pop_DB[count].population = r.population;
		count++;
	}

	if (Is_Full())
	{
		double_size();
		pop_DB[count].state_name = r.state_name;
		pop_DB[count].population = r.population;
	}
}

/******************************************************************************************************************************************************
Name: Search
Pre-Condition: will except a constant string named state. There is a dynamic array with population records in it, there is a count field that has been 
assigned a value, and a capacity field that has been assigned a value
Post-Condition:  the string state was compared to the state_name string field within the population record of each position in the array, if the position
was found, it returned the position, if the position was not found, it returned -1;
Description:searches for the string of a state within the dynamic array pop_DB
******************************************************************************************************************************************************/
int state_class::Search(const string& state)
{
	for (int i = 0; i < count; i++)
	{
		if (pop_DB[i].state_name == state)
		{
			return i;
		}
	}

	return -1;
}


/******************************************************************************************************************************************************
Name: Remove
Pre-Condition: a dynamic array of population records exists, there is also a count and capacity that have been initialized and assigned values. the 
state_pop_statistics.cpp file is about to attempt to call this function three times 
Post-Condition The string that was passed into the function found a match when compared to each of the state_name strings within the dynamic array.
the desired population record was removed and the array and count were adjusted for the change by reducing one from the count and changing the addresses 
of the following population records within the array
Description:This removes a population record from the dynamic array by locating the population record with the same state_name as the string that was passed into the function
******************************************************************************************************************************************************/
void state_class::Remove(const string& state)
{
	int j = Search(state);
	bool moveUp = false;

	if (j != -1)
	{
		for (int i = j; i < count - 1; i++)
		{
			pop_DB[i] = pop_DB[i + 1];
		}
		count--;
	}

}


/******************************************************************************************************************************************************
Name:Print_All_To_File
Pre-Condition: There exists a dynamic array of population records called pop_DB and a count and capacity have been initialized and had values set to them. 
Post-Condition: The contents of pop_DB have been copied to a .txt file with the state followed by the population in alphabetical order
Description: This takes the contents of pop_DB and copies it onto a .txt file that is named whatever string is passed into the function
******************************************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{
	ofstream fileout;
	fileout.open(filename); 

	for (int i = 0; i < count; i++)
	{
		fileout << pop_DB[i].state_name << " ";
		fileout << setprecision(0) << fixed << pop_DB[i].population << "\n";
	}
	fileout.close();
}
/******************************************************************************************************************************************************
Name: Print_ALL
Pre-Condition: There exists a dynamic array of population records as well as a count and a capacity that have already been initialized and assigned values
Post-Condition: The contents of the dynamic array were printed from the first population record within the array to the last population record
Description: prints the population records within pop_DB starting with the state and then population going down until the last population within the array
******************************************************************************************************************************************************/
void state_class::Print_ALL()
{
	for (int i = 0; i < count; i++)
	{
		cout << pop_DB[i].state_name << " ";
		cout << setprecision(0) << fixed << pop_DB[i].population << "\n";
	}
}


/******************************************************************************************************************************************************
Name: Print_Range
Pre-Condition: a dynamic array called pop_DB has population records in it, and there is a count int and capacity int that have both been initialized and assigned a value.
If this function is called, a constant int min and a constant int max will be passed into it.
Post-Condition: population_records were printed out that fit between the min and max that were passed, including the min and max values. the state_name and the population were both printed for each.
Description:prints out the range of population records by comparing the populations within each of the population records to the min and max passed into the function.
******************************************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
	double minTemp = min;
	double maxTemp = max;
	int tracker = 0;

	for (int i = 0; i < count; i++)
	{
		if (pop_DB[i].population >= minTemp && pop_DB[i].population <= maxTemp)
		{
			cout << pop_DB[i].state_name << " ";
			cout << pop_DB[i].population << "\n";
			tracker++;
		}
	}
	
}


/******************************************************************************************************************************************************
Name:State_Count
Pre-Condition: a constant int min and a constant int max will be passed into this function. a dynamic array of population records exists called pop_DB
and a count and capacity ints exist that have been initialized and assigned values
Post-Condition: the number of states that were between the min and max(included) was returned 
Description: returns the amount of states between the min and max(inclusive)
******************************************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{
	double minTemp = min;
	double maxTemp = max;
	int tracker = 0;

	for (int i = 0; i < count; i++)
	{
		if (pop_DB[i].population >= minTemp && pop_DB[i].population <= maxTemp)
		{
			tracker++;
		}
	}
	return tracker;
}

/******************************************************************************************************************************************************
Name:Sort
Pre-Condition: there is a population records dynamic array called pop_DB with a series of population records that have not been sorted alphabetically
Post-Condition: the dynamic array pop_DB has been sorted alphabetically from the first position within the array to the last filled position within the array
Description: sorts the population records alphabetically
******************************************************************************************************************************************************/
void state_class::Sort()
{
	population_record temp;

	for (int i = 1; i < count; i++)
	{
		temp = pop_DB[i];
		int j = i - 1;


		while ((j >= 0 && pop_DB[j].state_name > temp.state_name))
		{
			pop_DB[j + 1] = pop_DB[j];
			j = j - 1;
		}

		pop_DB[j + 1] = temp;
	}

}
