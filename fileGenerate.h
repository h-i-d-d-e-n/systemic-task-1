#ifndef fileGenerate_H_INCLUDED
#define fileGenerate_H_INCLUDED

#include "mylib.h"
#include "person.h"

void generateStudentsFile(const string& fileName, size_t);
void splitStudentsByGrade(const vector<Person>& students, const string& baseName);
void splitStudentsByGradeFromFile(const string& inputFilename, const string& baseName);

constexpr size_t ten_thousand = 10000;
constexpr size_t one_hundred_thousand = 100000;
constexpr size_t one_million = 1000000;
constexpr size_t ten_million = 10000000;

#endif
