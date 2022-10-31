#include <iostream>
#include <string>
#include "student.h"


using namespace std;

Student::Student()
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->studentAge = 0;
	for (int i = 0; i < daysArraySize; i++) this->daysToComplete[i] = 0;
	this->degreeProgram = DegreeProgram::UNDECLARED;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int studentAge, int daysToComplete[], DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	for (int i = 0; i < daysArraySize; i++) this->daysToComplete[i] = daysToComplete[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student(){}

//creating accessors (getters)
string Student::getStudentID() { return this->studentId; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getStudentAge() { return this->studentAge; }
const int* Student::getDaysToComplete() { return this->daysToComplete; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//creating mutators (setters)
void Student::setStudentID(string studentId) { this->studentId = studentId; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setStudentAge(int studentAge) { this->studentAge = studentAge; }
void Student::setDaysToComplete(const int daysToComplete[]) {
	for (int i = 0; i < daysArraySize; i++) this->daysToComplete[i] = daysToComplete[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::print()
{
	cout << this->studentId << '\t';
	cout << "First Name: " << this->firstName << '\t';
	cout << "Last Name: "<< this->lastName << '\t';
	cout << "Age: " << this->studentAge << '\t';
	cout << "daysInCourse: {" << this->daysToComplete[0] << ", " << this->daysToComplete[1] << ", " << this->daysToComplete[2] << "}\t";
	cout << "Degree Program: " << degreeProgramStrings[(int)this->degreeProgram] << endl;
}


