#include <iostream>
#include <string>
#include "roster.h"
#include "main.h"

using namespace std;

int main() {

	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"
	};
		
	string courseTitle = "C867 - Scripting and Programming: Applications";
	string progLang = "C++";
	string studId = "000215792";
	string studName = "Sean Tarnas";

	cout << courseTitle << endl << "Language: " << progLang << endl << "Student ID: " << studId << endl << "Name: " << studName << endl;

}