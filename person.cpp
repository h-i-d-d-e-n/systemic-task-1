#include "mylib.h"

class Person { // Person class definition

  public:
  string firstName, lastName;
  vector<int> homework;
  int examResults;
  double finalGrade;

  void gradeAverage() {
        finalGrade = accumulate(homework.begin(), homework.end(), 0.0) / static_cast<double>(homework.size()) * 0.4 + examResults * 0.6;
    };

  Person() { // Constructor

    firstName = "";
    lastName = "";
    examResults = 0;
    finalGrade = 0.0;
    // im not doing homework cause its already empty by default

  };

  Person(const Person& other) { // Copy constructor

    firstName = other.firstName;
    lastName = other.lastName;
    homework = other.homework;
    examResults = other.examResults;
    finalGrade = other.finalGrade;

  }

  Person& operator=(const Person& other) { // Copy assignment operator 

    if (this != &other) {  // it prevents potential storage reuse

      firstName = other.firstName;
      lastName = other.lastName;
      homework = other.homework;
      examResults = other.examResults;
      finalGrade = other.finalGrade;

    }

    return *this;
  }
  
  ~Person() { // Deconstructor
    // from what i can tell its not required to add anything inside as it all does it itself as a deconstructor
  }; 


  friend std::istream& operator>>(std::istream& inp, Person& student) {
    cout << "Enter first name: ";
    inp >> student.firstName;
    cout << "Enter last name: ";
    inp >> student.lastName;
    cout << "Enter number of homework grades: ";

    size_t n;
    inp >> n;
    student.homework.resize(n);
    cout << "Enter homework grades: ";
    for (size_t i = 0; i < n; ++i)
        inp >> student.homework[i];
    cout << "Enter exam grade: ";
    inp >> student.examResults;
    student.gradeAverage();  // recalculate final grade
    return inp;
};

  
  friend std::ostream& operator<<(std::ostream& out, const Person& student){
    out << left << setw(15) << student.firstName << setw(15) << student.lastName
    << fixed << setprecision(2) << setw(20) << student.finalGrade << endl;
    return out;
  }
};