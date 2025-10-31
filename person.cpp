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


  friend std::istream& operator>>(std::istream& inp, Person& student) {

    cout << "Enter first name: ";
    inp >> student.firstName;

    cout << "Enter last name: ";
    inp >> student.lastName;


    cout << "Please type either 'R' for random data or 'M' for manual data entry: ";
    char userAnswer;
    inp >> userAnswer;
    if (userAnswer == 'R' || userAnswer == 'r')
    {
      student.homework = student.generateRandomHomeworkGrades();
      student.examResults = student.generateRandomExamResult();
    }
    else if(userAnswer == 'M' || userAnswer == 'm')
    {
  
      cout << "Enter homework grades ('Exit' to stop): ";
      string userManualGrade;

      while (true) {
        inp >> userManualGrade; 

        if (userManualGrade == "Exit" || userManualGrade == "exit") {
          break; 
        }

        int userGrade = stoi(userManualGrade); 
        student.homework.push_back(userGrade); 
      }
      
      cout << "Enter exam grade: ";
      inp >> student.examResults;
        
    }    

    cout << "Choose method of final grade calculation: ";
    inp >> student.methodOfCalculation;
    if (student.methodOfCalculation == "average" || student.methodOfCalculation == "Average") {
    student.finalGrade = student.averagePath();
    }
      else if (student.methodOfCalculation == "median" || student.methodOfCalculation == "Median") {
        student.finalGrade = student.medianPath();
      }
      else {
        cout << "Please choose either median or average: ";
        inp >> student.methodOfCalculation;
      }
      if (student.methodOfCalculation == "median" || student.methodOfCalculation == "Median") {
        student.finalGrade = student.medianPath();
      }
      else {
        student.finalGrade = student.averagePath();
      }
      return inp;
    }

  friend std::ostream& operator<<(std::ostream& out, const Person& student){

    out << left << setw(15) << student.firstName << setw(15) << student.lastName
    << fixed << setprecision(2) << setw(20) << student.finalGrade << endl;

    // Show homework grades
    out << endl << endl << "   Homework grades: ";
    for (int grade : student.homework) {
        out << grade << " ";
    }

    // Show exam result
    out << "\n   Exam result: " << student.examResults << endl;
    out << "------------------------------------------------------" << endl;

    return out;
  }
};
