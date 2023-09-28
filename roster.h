#ifndef ROSTER_H_
#define ROSTER_H_

#include "student.h"
#include <string>
#include <vector>

class Roster {
	public:
		Student* classRosterArray[5];
		int lastIndex = -1;

		void parse(std::string row);
		void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void remove(std::string studentID);
		void printAll();
		void printAverageDaysInCourse(std::string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);

		// Deconstructor
		~Roster();
	private:
};

#endif /* ROSTER_H_ */
