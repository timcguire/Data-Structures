#include "Date.h"


/*************************************************************************************
Name: Thomas McGuire  Z#: Z23301770
Course: Data Structures and algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: January 29, 2021  Due Time: 11:59 PM
Total Points: 100 Assignment 3: Date Program

Description: This assignment demonstrates my understanding of C++ classes, implementing a class in C++,
Operator overloading with chaining, Preprocessor directives #ifndef, #define, and #endif, this- the pointer to the current object.
***************************************************************************************/

int main()
{
	Date myDate;
	Date herDate(11, 14, 1953);
	Date test1Date(25, 1, 1982);//should generate error message that says bad month
	Date test22Date(2, 29, 2020);//ok, should say leep year
	Date test3Date(2, 30, 2021);//should generate error message that bad day
	Date test4Date(1, 25, 0000);//should generate error message that bad year
	Date test5Date(80, 40, 0000);//should generate error that bad month, day, and year

	herDate.display();
	cout << "" << endl;
	cout << herDate.getMonth() << endl;
	cout << herDate.getDay() << endl;
	cout << herDate.getYear() << endl;
	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);
	cout << "myDate: " << myDate << " test22Date: " << test22Date << " herDate: " << herDate << endl;

	return 0;
}