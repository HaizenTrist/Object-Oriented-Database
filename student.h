#ifndef STUDENT_H_
#define STUDENT_H_

#include "degree.h"
#include <string>
#include <vector>
#include <iostream>

class Student {
	public:
		// Constructor
		Student (std::string inputID, std::string inputFirstName, std::string inputLastName, std::string inputEmail, int inputAge, int inputDays[], DegreeProgram inputProgram);
		// Print info for a student
		void print();

		// Mutators
		void SetID (std::string newID);
		void SetFirstName (std::string newFirstName);
		void SetLastName (std::string newLastName);
		void SetEmail (std::string newEmail);
		void SetAge (int newAge);
		void SetDays (int newDays[]);
		void SetProgram (DegreeProgram newProgram);

		// Accessors
		std::string GetID();
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetEmail();
		int GetAge();
		int* GetDays();
		DegreeProgram GetProgram();
	private:
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string emailAddress;
		int age;
		int daysInCourse[3];
		DegreeProgram degreeProgram;
};

#endif /* STUDENT_H_ */
