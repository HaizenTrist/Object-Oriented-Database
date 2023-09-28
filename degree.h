#ifndef DEGREE_H_
#define DEGREE_H_
#include <string>

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Used to convert DegreeProgram data type to string for output purposes.
static const std::string DegreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

#endif /* DEGREE_H_ */
