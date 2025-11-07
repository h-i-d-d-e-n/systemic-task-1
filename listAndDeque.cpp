#include "listAndDeque.h"
#include "fileGenerate.h"
#include "mylib.h"
#include "person.h"
#include "timer.h"

static bool compareByGrade(const Person& a, const Person& b) {
    return a.averagePath() < b.averagePath();
}

void processStudentsList(const string& inputFile, const string& baseName) {
    Timer t;
    ifstream in(inputFile);
    if (!in) {
        cout << "open fail " << inputFile << "\n";
        return;
    }

    string header;
    getline(in, header);

    t.start();
    list<Person> studentsList;
    Person s;
    int hw1, hw2, hw3, hw4, hw5, exam;

    while (in >> s.firstName >> s.lastName >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam) {
        s.homework = {hw1, hw2, hw3, hw4, hw5};
        s.examResults = exam;
        studentsList.push_back(s);
    }
    double readMs = t.elapsedMs();

    t.start();
    studentsList.sort(compareByGrade);
    double sortMs = t.elapsedMs();

    t.start();
    string goodFile = baseName + "_list_Good.txt";
    string badFile  = baseName + "_list_Bad.txt";

    ofstream goodOut(goodFile);
    ofstream badOut(badFile);

    size_t goodCount = 0;
    size_t badCount = 0;

    for (const auto& p : studentsList) {
        double finalAvg = p.averagePath();
        if (finalAvg >= 5.0) {
            goodOut << p.firstName << ' ' << p.lastName << ' '
                    << fixed << setprecision(2) << finalAvg << '\n';
            ++goodCount;
        } else {
            badOut << p.firstName << ' ' << p.lastName << ' '
                   << fixed << setprecision(2) << finalAvg << '\n';
            ++badCount;
        }
    }
    double splitWriteMs = t.elapsedMs();

    cout << baseName << " list read(ms): " << readMs
         << " sort(ms): " << sortMs
         << " split+write(ms): " << splitWriteMs
         << " passed: " << goodCount
         << " failed: " << badCount << "\n";
}

void processStudentsDeque(const string& inputFile, const string& baseName) {
    Timer t;
    ifstream in(inputFile);
    if (!in) {
        cout << "open fail " << inputFile << "\n";
        return;
    }

    string header;
    getline(in, header);

    t.start();
    deque<Person> studentsDeque;
    Person s;
    int hw1, hw2, hw3, hw4, hw5, exam;

    while (in >> s.firstName >> s.lastName >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam) {
        s.homework = {hw1, hw2, hw3, hw4, hw5};
        s.examResults = exam;
        studentsDeque.push_back(s);
    }
    double readMs = t.elapsedMs();

    t.start();
    sort(studentsDeque.begin(), studentsDeque.end(), compareByGrade);
    double sortMs = t.elapsedMs();

    t.start();
    string goodFile = baseName + "_deque_Good.txt";
    string badFile  = baseName + "_deque_Bad.txt";

    ofstream goodOut(goodFile);
    ofstream badOut(badFile);

    size_t goodCount = 0;
    size_t badCount = 0;

    for (const auto& p : studentsDeque) {
        double finalAvg = p.averagePath();
        if (finalAvg >= 5.0) {
            goodOut << p.firstName << ' ' << p.lastName << ' '
                    << fixed << setprecision(2) << finalAvg << '\n';
            ++goodCount;
        } else {
            badOut << p.firstName << ' ' << p.lastName << ' '
                   << fixed << setprecision(2) << finalAvg << '\n';
            ++badCount;
        }
    }
    double splitWriteMs = t.elapsedMs();

    cout << baseName << " deque read(ms): " << readMs
         << " sort(ms): " << sortMs
         << " split+write(ms): " << splitWriteMs
         << " passed: " << goodCount
         << " failed: " << badCount << "\n";
}
