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
	string studentAge;
	double daysToComplete[daysArraySize];
	DegreeProgram degreeProgram;
public:
	Student();

	Student(string studentId, string firstName, string lastName, string emailAddress, string studentAge, double daysToComplete[], DegreeProgram degreeProgram);
	~Student();

	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getStudentAge();
	const double* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	void setID(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setStudentAge(string studentAge);
	void setDaysToComplete(const double daysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader();

	void print();

};