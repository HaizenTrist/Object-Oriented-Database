cmake_minimum_required(VERSION 3.10)

# Set some basic project attributes
project (jym1
	VERSION 0.1
	DESCRIPTION "oof")

# This project will output an executable file
add_executable(${PROJECT_NAME} 
	main.cpp 
	student.cpp 
	roster.cpp)