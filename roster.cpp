#include "roster.h"

#include <sstream>

void Roster::parse (std::string studentDataRow) {
	int delimPrev = -1;
	int delimNext = studentDataRow.find(",");
	std::string parseArray[8] = {};
	int i = 0;

	do {
		parseArray[i] = studentDataRow.substr(delimPrev+1, (delimNext-delimPrev)-1);
		delimPrev = delimNext;
		delimNext = studentDataRow.find(",", delimPrev+1);
		i = i + 1;
	} while (delimNext != -1);

	std::string studentID = parseArray[0];
	std::string firstName = parseArray[1];
	std::string lastName = parseArray[2];
	std::string emailAddress = parseArray[3];
	int age = stoi(parseArray[4]);
	int daysInCourse1 = stoi(parseArray[5]);
	int daysInCourse2 = stoi(parseArray[6]);
	int daysInCourse3 = stoi(parseArray[7]);

	DegreeProgram degreeProgram = SECURITY;
	if (studentDataRow.back() == 'E') degreeProgram = SOFTWARE;
	else if (studentDataRow.back() == 'K') degreeProgram = NETWORK;

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
}

void Roster::remove(std::string studentID) {
	bool found = false;
	for (int i=0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->GetID() == studentID) {
			found = true;
			if (i < 4) {
				Student* deleteme = classRosterArray[i];
				classRosterArray[i] = classRosterArray[4];
				classRosterArray[4] = deleteme;
			}
			Roster::lastIndex--;
		}
	}
	std::cout << "Removing student " << studentID << " from roster..." << std::endl;
	if (found) {std::cout << "Success." << std::endl;}
	else std::cout << "Error: Student " << studentID << " not found." << std::endl;
}

void Roster::printAll() {
	std::cout << "==========================================================" << std::endl;
	std::cout << "Roster\n-------------------------------------------------" << std::endl;
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
	std::cout << "==========================================================" << std::endl;
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
    	std::string id = classRosterArray[i]->GetID();
        if (id==studentID) {
            std::cout << id << ": " << ( classRosterArray[i]->GetDays()[0] + classRosterArray[i]->GetDays()[1] + classRosterArray[i]->GetDays()[2] ) /3 << std::endl;
        }
    }
}

void Roster::printInvalidEmails() {
	std::cout << "==========================================================" << std::endl;
	std::cout << "Invalid Emails\n-------------------------------------------------" << std::endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		std::string email = (classRosterArray[i]->GetEmail());
		std::string id = (classRosterArray[i]->GetID());
		if ((email.find("@") == std::string::npos) || (email.find(" ") != std::string::npos) || (email.find(".") == std::string::npos)) { std::cout << id << ": " << email << std::endl; }
	}
	std::cout << "==========================================================" << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	std::cout << "==========================================================" << std::endl;
	std::cout << "Degree Program: " << DegreeProgramStrings[degreeProgram] << "\n-------------------------------------------------" << std::endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->GetProgram() == degreeProgram) classRosterArray[i]->print();
    }
	std::cout << "==========================================================" << std::endl;
}

Roster::~Roster() {
    for (int i=0; i < 4; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
