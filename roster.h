#include <string>
#include <cstring>
#include <iostream>
#include "student.h"

using namespace std;


class Roster
{
private:
	int lastIndex;
	int maxSeats;
	Student** classRosterArray;

public:

	Roster();
	Roster(int maxSeats);


	Student* getStudentData(int index);
	void parseStudentData(string row);
	void add(string studentId, string firstName, string lastName, string emailAddress,
		int studentAge, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram);
	void remove(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);


	~Roster();


};