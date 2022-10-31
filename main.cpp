#include <iostream>
#include <string>
#include "roster.h"


using namespace std;

int main() {

	int numStudents = 5;
	const string studentData[5] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Sean,Tarnas,sean1234@wgu.edu,31,10,15,20,SOFTWARE"
	};
		
	string courseTitle = "C867 - Scripting and Programming: Applications";
	string progLang = "C++";
	string studId = "000215792";
	string studName = "Sean Tarnas";

	cout << courseTitle << endl << "Language: " << progLang << endl << "Student ID: " << studId << endl << "Name: " << studName << endl << endl;

	// Creates new roster
	Roster* roster = new Roster(numStudents);
	
	//Adds studentData to newly created roster
	for (int i = 0; i < numStudents; i++) {
		roster->parseStudentData(studentData[i]);
	}

	//Prints all student data in roster
	cout << "Student roster: \n";
	roster->printAll();

	//Prints all invalid email addresses in the roster
	cout << "Displaying invalid emails:" << endl << endl;
	roster->printInvalidEmails();
	cout << endl;


	//Prints the average days spent in a course for all students
	cout << "Average days spent in a course for all students: \n";
	for (int i = 0; i < numStudents; i++) {
		roster->printAverageDaysInCourse(roster->getStudentData(i)->getStudentID());
	}

}