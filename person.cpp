#include "mylib.h"

class Person { // Person class definition

  public:
  string firstName, lastName;
  vector<int> homework;
  int examResults;
  double finalGrade;

  string methodOfCalculation;


  double gradeAverage () { // changed to double so functions would work and plus its more accurate
    return accumulate(homework.begin(), homework.end(), 0.0) / static_cast<double>(homework.size());
  };

  double averagePath () {
    double fullAverageGrade;
    fullAverageGrade = gradeAverage() * 0.4 + examResults * 0.6;
    return fullAverageGrade;
  };

  double medianPath () {
    double fullMedianGrade;
    fullMedianGrade = gradeMedian() * 0.4 + examResults * 0.6;
    return fullMedianGrade;
  };


  vector<int> generateRandomHomeworkGrades(int minimumGrades = 1, int maximumGrades = 10) {

    vector<int> randomGradesVector;

    size_t numberOfGrades = rand() % 10 + 1;

    for (size_t i = 0; i < numberOfGrades; ++i) {
      int randomGrade = rand() % (maximumGrades - minimumGrades + 1) + minimumGrades;
      randomGradesVector.push_back(randomGrade);
    }

    return randomGradesVector;
  }

  int generateRandomExamResult(int minimumGrade = 1, int maximumGrade = 10) {

    int randomExamResult = rand() % (maximumGrade - minimumGrade + 1) + minimumGrade;
    return randomExamResult;
  }


  double gradeMedian() { // changed to double so functions would work and plus its more accurate
    if (homework.size() % 2 == 0) {

      size_t size;
      size_t middlePoint_A;
      size_t middlePoint_B;
      double median;

      size = homework.size();
      middlePoint_A = size/2 ;
      middlePoint_B = (size/2) + 1;
      median = (homework.at(middlePoint_A) + homework.at(middlePoint_B)) / 2;
      return median;
    }
    else
    {
    if (homework.size() % 2 != 0) {

      size_t size;
      size_t middlePoint;
      double median;

      size = homework.size();
      middlePoint = size / 2;
      median = homework.at(middlePoint);
      return median;
    }
   } // placeholder return to avoid compiler error
  };

  Person() { // Constructor

    firstName = "";
    lastName = "";
    examResults = 0;
    finalGrade = 0.0;
    // im not doing homework cause its already empty by default

  }

  Person(const Person& other) { // Copy constructor

    firstName = other.firstName;
    lastName = other.lastName;
    homework = other.homework;
    examResults = other.examResults;
    finalGrade = other.finalGrade;

    methodOfCalculation = other.methodOfCalculation;

  }

  Person& operator=(const Person& other) { // Copy assignment operator

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

  ~Person() { // Deconstructor
    // from what i can tell its not required to add anything inside as it all does it itself as a deconstructor
  }
};