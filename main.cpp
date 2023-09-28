#include "student.h"
#include "roster.h"

int main() {
	std::cout << "==========================================================" << std::endl;
	std::cout << "Course: Scripting and Programming - Applications\nLanguage: C++\nStudent ID: 010865879\nName: Aqib Hossain" << std::endl;
	std::cout << "==========================================================" << std::endl;
	std::cout << "\n\n" << std::endl;
	const std::string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Aqib,Hossain,ahoss16@gmail.com,18,34,23,21,SOFTWARE"};

	Roster classRoster;
	for (int i = 0; i < 5; i++) classRoster.parse(studentData[i]);

	classRoster.printAll();
	std::cout << "\n\n" << std::endl;

	classRoster.printInvalidEmails();
	std::cout << "\n\n" << std::endl;

	std::cout << "==========================================================" << std::endl;
	std::cout << "Average Days in Course\n-------------------------------------------------" << std::endl;
	for (int i = 0; i < 5; i++) { classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetID()); }
	std::cout << "==========================================================" << std::endl;
	std::cout << "\n\n" << std::endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	std::cout << "\n\n" << std::endl;

	classRoster.remove("A3");
	std::cout << "\n\n" << std::endl;

	classRoster.printAll();
	std::cout << "\n\n" << std::endl;

	classRoster.remove("A3");
	std::cout << "\n\n" << std::endl;

	classRoster.~Roster();
}
