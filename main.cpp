#include "mylib.h"
#include "person.cpp"

int main()
{
  srand(time(nullptr)); // seed random generator

  int numberOfStudents;
    cout << "Enter number of students: ";
    cin >> numberOfStudents;
    vector<Person> students(numberOfStudents);

    for (int i = 0; i < numberOfStudents; ++i) {
        cout << "\nEnter data for student #" << i + 1 << ":\n";
        cin >> students[i];
    }


    // Output
    cout << left << setw(15) << "Name" << setw(15) << "Surname" << setw(20) << "Final_Point" << endl;
    cout << "------------------------------------------------------" << endl;
    for (const auto &s : students) {
      cout << s;
    }
    return 0;
  };

