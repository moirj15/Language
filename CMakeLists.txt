
project(Jay_Lang)
add_executable(
	Jay_lang
	main.cpp
	scanner.cpp
	scanner.h
	utils.cpp
	utils.h
	errorLog.cpp
	errorLog.h
	ast.h
    ast.cpp
	parser.h
	parser.cpp
)

set(CMAKE_CXX+FLAGS "-std=c++11 -Wall -Wextra -pedantic")
