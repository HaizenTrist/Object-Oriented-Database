#include "degree.h"
#include "student.h"

// Constructor
Student::Student(std::string inputID, std::string inputFirstName, std::string inputLastName, std::string inputEmail, int inputAge, int inputDays[], DegreeProgram inputProgram) {
	studentID = inputID;
	firstName = inputFirstName;
	lastName = inputLastName;
	emailAddress = inputEmail;
	age = inputAge;
	for (int i = 0; i < 3; i++) daysInCourse[i] = inputDays[i];
	degreeProgram = inputProgram;
}

// Print info for a given student
void Student::print() {
    std::cout << "Student ID: " << GetID() << "\t\t";
    std::cout << "First Name: " << GetFirstName() << "\t";
    std::cout << "Last Name: " << GetLastName() << "\t";
    std::cout << "Email: " << GetEmail() << "\t\t";
    std::cout << "Age: " << GetAge() << "\t\t";
    std::cout << "Days in Course: " << GetDays()[0] << ',' << GetDays()[1] << ',' << GetDays()[2] << "\t";
    std::cout << "Degree Program: " << DegreeProgramStrings[GetProgram()] << "\n";
}

// Mutators
void Student::SetID (std::string newID) {studentID = newID;}
void Student::SetFirstName (std::string newFirstName) {firstName = newFirstName;}
void Student::SetLastName (std::string newLastName) {lastName = newLastName;}
void Student::SetEmail (std::string newEmail) {emailAddress = newEmail;}
void Student::SetAge (int newAge) {age = newAge;}
void Student::SetDays (int newDays[]) { for (int i = 0; i < 3; i++) daysInCourse[i] = newDays[i]; }
void Student::SetProgram (DegreeProgram newProgram) {degreeProgram = newProgram;}

// Accessors
std::string Student::GetID() {return studentID;}
std::string Student::GetFirstName() {return firstName;}
std::string Student::GetLastName() {return lastName;}
std::string Student::GetEmail() {return emailAddress;}
int Student::GetAge() {return age;}
int* Student::GetDays() {return daysInCourse;}
DegreeProgram Student::GetProgram() {return degreeProgram;}
