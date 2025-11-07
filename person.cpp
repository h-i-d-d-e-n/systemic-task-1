#include "person.h"

 // Person class definition

  double Person::gradeAverage() const {
    if (homework.empty()) return 0.0;
    return accumulate(homework.begin(), homework.end(), 0.0) / static_cast<double>(homework.size());
}

  double Person::gradeMedian() const { // upgraded formula, mine wasnt correct
    if (homework.empty()) return 0.0;
    vector<int> temp = homework;       
    std::sort(temp.begin(), temp.end());
    size_t n = temp.size();
    if (n % 2 == 1) {
        return static_cast<double>(temp[n / 2]);
    } else {
        return (static_cast<double>(temp[n/2 - 1]) + static_cast<double>(temp[n/2])) / 2.0;
    }
}

  double Person::averagePath () const{
    double fullAverageGrade;
    fullAverageGrade = gradeAverage() * 0.4 + examResults * 0.6;
    return fullAverageGrade;
  };

  double Person::medianPath () const{
    double fullMedianGrade;
    fullMedianGrade = gradeMedian() * 0.4 + examResults * 0.6;
    return fullMedianGrade;
  };


  Person::Person() { // Constructor

    firstName = "";
    lastName = "";
    examResults = 0;
    finalGrade = 0.0;
    // im not doing homework cause its already empty by default

  }

  Person::Person(const Person& other) { // Copy constructor

    firstName = other.firstName;
    lastName = other.lastName;
    homework = other.homework;
    examResults = other.examResults;
    finalGrade = other.finalGrade;

    methodOfCalculation = other.methodOfCalculation;
  }

  Person& Person::operator=(const Person& other) { // Copy assignment operator

    if (this != &other) {  // it prevents potential storage reuse

      firstName = other.firstName;
      lastName = other.lastName;
      homework = other.homework;
      examResults = other.examResults;
      finalGrade = other.finalGrade;

      methodOfCalculation = other.methodOfCalculation;
    };
    return *this;
  }

  Person::~Person() { // Deconstructor
    // from what i can tell its not required to add anything inside as it all does it itself as a deconstructor
  }

