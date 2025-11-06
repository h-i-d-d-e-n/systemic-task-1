#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include "mylib.h"

class Person {
public:
    // Constructors
    Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    // Fields 
    string firstName;
    string lastName;
    string methodOfCalculation;
    vector<int> homework;
    int examResults;
    double finalGrade;

    // Methods
    double gradeAverage() const;
    double gradeMedian() const;
    double averagePath() const;
    double medianPath() const;
};

#endif 
