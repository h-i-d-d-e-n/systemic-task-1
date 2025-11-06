#include "fileGenerate.h"
#include "timer.h"

int main() {
    srand(time(nullptr));
    Timer t;

    t.start();
    generateStudentsFile("Students_10k.txt", ten_thousand);
    cout << "gen 10k: " << t.elapsedMs() << " ms\n";

    // generate others...
    t.start();
    generateStudentsFile("Students_100k.txt", one_hundred_thousand);
    cout << "gen 100k: " << t.elapsedMs() << " ms\n";

    t.start();
    generateStudentsFile("Students_1M.txt", one_million);
    cout << "gen 1M: " << t.elapsedMs() << " ms\n";

    t.start();
    generateStudentsFile("Students_10M.txt", ten_million);
    cout << "gen 10M: " << t.elapsedMs() << " ms\n";

    vector<string> files = { "Students_10k.txt", "Students_100k.txt", "Students_1M.txt", "Students_10M.txt" };

    for (auto& name : files) {
        ifstream in(name);
        if (!in) continue;

        string line;
        getline(in, line);

        if (name == "Students_1M.txt" || name == "Students_10M.txt") {
            in.close();
            t.start();
            splitStudentsByGradeFromFile(name, name.substr(0, name.find(".txt")));
            cout << "process " << name << ": " << t.elapsedMs() << " ms\n";
            continue;
        }

        vector<Person> students;
        Person s;
        int hw1, hw2, hw3, hw4, hw5, exam;

        t.start();
        while (in >> s.firstName >> s.lastName >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam) {
            s.homework = {hw1, hw2, hw3, hw4, hw5};
            s.examResults = exam;
            students.push_back(s);
        }
        cout << "read " << name << ": " << t.elapsedMs() << " ms\n";

        t.start();
        splitStudentsByGrade(students, name.substr(0, name.find(".txt")));
        cout << "split " << name << ": " << t.elapsedMs() << " ms\n";
    }

    return 0;
}