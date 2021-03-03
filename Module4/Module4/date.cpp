#include "Date.h"

//Date.cpp

//****************************************************************************************************
//Name:		Date defaukt constructor
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description:		This is the default constructor which will be called automatically when
//an object is declared.	It will initialize the state of the class
//
//****************************************************************************************************

Date::Date()
{
	cout << "Default constructor has been called" << endl;
	this->myMonth = 01;
	this->myDay = 01;
	this->myYear = 0001;
	cout << setfill('0') << setw(2) << this->myMonth << "/" << setfill('0') << setw(2) << this->myDay << "/" << setfill('0') << setw(4) << this->myYear << "\n" << endl;
}

//****************************************************************************************************
//Name:		Date explicit value constructor
//Precondition: no date object has been created yet, 3 values will be passed into this constructor to initialize the private data
//Postcondition: the state of the object has been initialized to today's date
//Description: this explicit value constructor gets called when values are passed to be initialized
//
//
//****************************************************************************************************

Date::Date(unsigned m, unsigned d, unsigned y)
{
	int error = 0;

	cout << "Explicit-value constructor has been called" << endl;
	this->myMonth = m;
	if (this->myMonth < 1 || this->myMonth > 12)
	{
		cout << "Month = " << this->myMonth << " is incorrect" << endl;
		error = 1;
	}
	
	this->myDay = d;
	if (this->myMonth % 2 != 0)
	{
		if (this->myMonth == 9|| this->myMonth == 11)
		{
			if (this->myDay > 30)
			{
				cout << "day = " << this->myDay << " is incorrect" << endl;
				error = 1;
			}
		}
	}
	else
	{
		if (this->myMonth == 8 || this->myMonth == 10 || this->myMonth == 12)
		{
			if (this->myDay > 31)
			{
				cout << "day = " << this->myDay << " is incorrect" << endl;
				error = 1;
			}
		}

		else if (this->myDay > 30)
		{
			cout << "day = " << this->myDay << " is incorrect" << endl;
			error = 1;
		}
	}
	
	this->myYear = y;
	if (this->myYear < 0)
	{
		cout << "Year = " << this->myYear << " is incorrect" << endl;
		error = 1;
	}

	if (this ->myYear == 0)
	{
		cout << "Year = " << setfill('0') << setw(4) << this->myYear << " is incorrect" << endl;
		error = 1;
	}

	if ((this->myYear % 4) == 0)
	{
		if (this->myYear % 100 == 0)
		{
			if (this->myYear % 400)
			{
				if (this->myMonth == 2)
				{
					if (this->myDay > 29)
					{
						cout << "day = " << this->myDay << " is incorrect" << endl;
						error = 1;
					}
				}
				else
				{
					this->display();
					cout << "This is a leap year" << endl;
				}
			}
			
		}
		else
		{
			if (this->myMonth == 2)
			{
				if (this->myDay > 29)
				{
					cout << "day = " << this->myDay << " is incorrect" << endl;
					error = 1;
				}
			}
			this->display();
			cout << "This is a leap year" << endl;
		}
	}
	else if (this->myMonth == 2)
	{
		if (this->myDay > 28)
		{
			cout << "day = " << this->myDay << " is incorrect" << endl;
			error = 1;
		}
	}
	else if (error != 1)
	{
		this->display();
	}
	cout << "" << endl;
}

//****************************************************************************************************
//			Display
//Precondition: a Date object has been initialized
//postcondition: The month, day, and year within the Date object were printed out to the system
//Description: displays the month day and year to the user
//
//
//****************************************************************************************************


void Date::display()
{
	cout << this->myMonth << "/" << this->myDay << "/" << this->myYear << endl;


}

//*****************************************************************************************************
//			getMonth
//Precondition: a Date object has been initialized
//Postcondition: the private data myMonth is returned
//Description: this accesses the private data myMonth
//
//
//*****************************************************************************************************
int Date::getMonth()
{

	return this->myMonth;

}

//*****************************************************************************************************
//			getDay
//Precondition:a Date object has been initialized
//Postcondition: the private data myDay is returned
//Description: this accesses the private data myDay
//
//
//*****************************************************************************************************

int Date::getDay()
{

	return this->myDay;

}

//*****************************************************************************************************
//			getYear
//Precondition: a Date object has been initialized
//Postcondition: the private data myYear is returned 
//Description: this accesses the private data myYear
//
//
//*****************************************************************************************************

int Date::getYear()
{

	return this->myYear;

}

//*****************************************************************************************************
//			setMonth
//Precondition: a Date object has been initialized
//Postcondition: the myMonth data has been changed to the passed value
//Description: changes the month in the date
//
//
//*****************************************************************************************************

void Date::setMonth(unsigned m)
{
	this->myMonth = m;


}

//*****************************************************************************************************
//			setDay
//Precondition: a Date object has been initialized
//Postcondition: the myDay data has been changed to the passed value
//Description: changes the montth in the date
//
//
//*****************************************************************************************************
void Date::setDay(unsigned d)
{
	this->myDay = d;


}

//*****************************************************************************************************
//			setYear
//Precondition: a Date object has been initialized
//Postcondition: the myYear data has been changed to the passed value
//Description: changes the year in the date
//
//
//*****************************************************************************************************

void Date::setYear(unsigned y)
{

	this->myYear = y;

}

//*****************************************************************************************************
//Name: chain operator
//Precondition: A Date object is initialized
//Postcondition: a Date object was passed in to the function and the ostream was return with the date and the proper format of the Date object that was passed in
//Description: outputs the Date of whatever date object is passed into this method
//
//
//*****************************************************************************************************

ostream& operator<<(ostream& out, Date& dateObj)
{
	string month;
	string day;
	string year;
	if (dateObj.getMonth() < 10)
	{
		out << setfill('0') << setw(2) << dateObj.getMonth() << "/";
	}
	else
	{
		out << dateObj.getMonth() << "/";
	}
	if (dateObj.getDay() < 10)
	{
		out << setfill('0') << setw(2) << dateObj.getDay() << "/";
	}
	else
	{
		out << dateObj.getDay() << "/";
	}
	if (dateObj.getYear() > 10)
	{
		if (dateObj.getYear() > 100 && dateObj.getYear() < 1000)
		{
			out << setfill('0') << setw(1) << dateObj.getYear();
		}
		if (dateObj.getYear() >= 1000)
		{
			out << dateObj.getYear();
		}
	}
	else
	{
		out << setfill('0') << setw(3) << dateObj.getYear();
	}
	

	return out;
}

