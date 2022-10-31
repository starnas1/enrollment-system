#include "degree.h"

using namespace std;

class Student {
public:
	const static int daysArraySize = 3;
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int daysToComplete[daysArraySize];
	DegreeProgram degreeProgram;
public:
	Student();

	Student(string studentId, string firstName, string lastName, string emailAddress, int studentAge, int daysToComplete[], DegreeProgram degreeProgram);

	~Student();

	//creating accessors (getters)
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getStudentAge();
	const int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	//creating mutators (setters)
	void setStudentID(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setStudentAge(int studentAge);
	void setDaysToComplete(const int daysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();

};