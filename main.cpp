#include "fileGenerate.h"
#include "listAndDeque.h"

int main() {
    srand(time(nullptr));

    generateStudentsFile("Students_1k.txt", one_thousand);
    generateStudentsFile("Students_10k.txt", ten_thousand);
    generateStudentsFile("Students_100k.txt", one_hundred_thousand);
    generateStudentsFile("Students_1M.txt", one_million);
    generateStudentsFile("Students_10M.txt", ten_million);

    vector<string> files = {
        "Students_1k.txt",
        "Students_10k.txt",
        "Students_100k.txt",
        "Students_1M.txt",
        "Students_10M.txt"
    };

    for (auto& name : files) {
        ifstream in(name);
        if (!in) continue;

        string line;
        getline(in, line);

        if (name == "Students_1M.txt" || name == "Students_10M.txt") {
            in.close();
            splitStudentsByGradeFromFile(name, name.substr(0, name.find(".txt")));
            continue;
        }

        vector<Person> students;
        Person s;
        int hw1, hw2, hw3, hw4, hw5, exam;

        while (in >> s.firstName >> s.lastName >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam) {
            s.homework = {hw1, hw2, hw3, hw4, hw5};
            s.examResults = exam;
            students.push_back(s);
        }

        splitStudentsByGrade(students, name.substr(0, name.find(".txt")));
    }

    for (auto& name : files) {
        string base = name.substr(0, name.find(".txt"));
        processStudentsList(name, base);
        processStudentsDeque(name, base);
    }

    return 0;
}
