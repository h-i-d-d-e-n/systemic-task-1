cmake_minimum_required(VERSION 3.10)
project(StudentSorter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(student_sorter
    main.cpp
    person.cpp
    person.h
    timer.cpp
    timer.h
    fileGenerate.cpp
    fileGenerate.h
    listAndDeque.cpp
    listAndDeque.h
    mylib.h
)