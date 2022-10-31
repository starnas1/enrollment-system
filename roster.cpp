#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include "roster.h"

using namespace std;

Roster::Roster()
{
	this->lastIndex = -1;
	this->maxSeats = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int maxSeats)
{
	this->lastIndex = -1;
	this->maxSeats = maxSeats;
	this->classRosterArray = new Student * [maxSeats];
}

Student* Roster::getStudentData(int index)
{
	return classRosterArray[index];
}

void Roster::parseStudentData(string row)
{
	if (lastIndex < maxSeats) {
		
		//Parse StudentID
		int rhs = row.find(',');
		string studentId = row.substr(0, rhs);

		//Parse first name
		int lhs = (rhs + 1);
		rhs = row.find(',', lhs);
		string firstName = row.substr(lhs, rhs - lhs);

		//Parse last name
		lhs = (rhs + 1);
		rhs = row.find(',', lhs);
		string lastName = row.substr(lhs, rhs - lhs);

		//Parse email
		lhs = (rhs + 1);
		rhs = row.find(',', lhs);
		string emailAddress = row.substr(lhs, rhs - lhs);

		//Parse student age
		lhs = (rhs + 1);
		rhs = row.find(',', lhs);
		int studentAge = stoi(row.substr(lhs, rhs - lhs));

		//Parse days in course #1
		lhs = (rhs + 1);
		rhs = row.find(',', lhs);
		int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

		//Parse days in course #2
		lhs = (rhs + 1);
		rhs = row.find(',', lhs);
		int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

		//Parse days in course #3
		lhs = (rhs + 1);
		rhs = row.find(',', lhs);
		int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

		//Parse degree program
		DegreeProgram degreeProgram;
		lhs = (rhs + 1);
		rhs = row.find(',', lhs);
		string degreeData = row.substr(lhs, rhs - lhs);

		if (degreeData == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}

		else if (degreeData == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
		}

		else if (degreeData == "SOFTWARE") {
			degreeProgram = DegreeProgram::SOFTWARE;
		}

		else if (degreeData == "UNDECLARED") {
			degreeProgram = DegreeProgram::UNDECLARED;
		}

		else {
			cerr << "Degree Program input not valid.";
			exit(-1);
		}

		add(studentId, firstName, lastName, emailAddress, studentAge, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

	}
	else {
		cerr << "Too many students listed. Now exiting.";
		exit(-1);
	}
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress,
	int studentAge, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram) {

	int daysToComplete[Student::daysArraySize];
	daysToComplete[0] = daysToComplete1;
	daysToComplete[1] = daysToComplete2;
	daysToComplete[2] = daysToComplete3;

	classRosterArray[++lastIndex] = new Student(studentId, firstName, lastName, emailAddress, studentAge, daysToComplete, degreeProgram);


}
void Roster::remove(string studentId)
{
	int currLastIndex = lastIndex;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentId)
		{
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[lastIndex];
			Roster::lastIndex--;
			cout << "Student with Student ID " << studentId << " has been removed from Class Roster." << endl;
		}
	}
	if (currLastIndex == lastIndex) {
		cout << "Student with Student ID " << studentId << " not found." << endl;
	}
}

void Roster::printAll()
{
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentId)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentId)
		{
			cout << "Student ID: " << studentId << ", average days in course is: ";
			cout << (classRosterArray[i]->getDaysToComplete()[0] +
				classRosterArray[i]->getDaysToComplete()[1] +
				classRosterArray[i]->getDaysToComplete()[2]) / 3 << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getEmailAddress().find(' ') != string::npos)
		{
			cout << classRosterArray[i]->getEmailAddress() << " - is invalid." << endl;
		}
		else if ((classRosterArray[i]->getEmailAddress().find('.') == string::npos) ||
			(classRosterArray[i]->getEmailAddress().find('@') == string::npos))
		{	cout << classRosterArray[i]->getEmailAddress() << " - is invalid." << endl;

		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i < maxSeats; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] == nullptr;
	}
}
