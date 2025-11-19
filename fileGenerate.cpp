#include "person.h"
#include "fileGenerate.h"

void generateStudentsFile(const string& fileName, size_t count) {
    ofstream out(fileName);
    if (!out) throw std::runtime_error("Could not open file for writing: " + fileName);

    out << "FirstName LastName HW1 HW2 HW3 HW4 HW5 Exam\n";

    for (size_t i = 1; i <= count; ++i) {
        out << "Name" << i << ' ' << "Surname" << i;
        for (int k = 0; k < 5; ++k) {
            int r = (std::rand() % 10) + 1;
            out << ' ' << r;
        }
        int exam = (std::rand() % 10) + 1;
        out << ' ' << exam << '\n';
    }
}

void splitStudentsByGrade(const vector<Person>& students, const string& baseName) {
    string goodFile = baseName + "_Good.txt";
    string badFile  = baseName + "_Bad.txt";

    ofstream goodOut(goodFile);
    ofstream badOut(badFile);
    if (!goodOut || !badOut) throw std::runtime_error("Could not open output files for base: " + baseName);

    goodOut << "FirstName LastName FinalGrade\n";
    badOut  << "FirstName LastName FinalGrade\n";

    for (const auto& p : students) {
        double finalAvg = p.averagePath();
        if (finalAvg >= 5.0) {
            goodOut << p.firstName << ' ' << p.lastName << ' ' << std::fixed << std::setprecision(2) << finalAvg << '\n';
        } else {
            badOut << p.firstName << ' ' << p.lastName << ' ' << std::fixed << std::setprecision(2) << finalAvg << '\n';
        }
    }
}

void splitStudentsByGradeFromFile(const string& inputFilename, const string& baseName) {
    std::ifstream in(inputFilename);
    if (!in) throw std::runtime_error("Input file open failed: " + inputFilename);

    string goodFile = baseName + "_Good.txt";
    string badFile  = baseName + "_Bad.txt";

    ofstream goodOut(goodFile);
    ofstream badOut(badFile);
    if (!goodOut || !badOut) throw std::runtime_error("Could not open output files for " + baseName);

    string header;
    if (!std::getline(in, header)) throw std::runtime_error("Empty input file: " + inputFilename);

    string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        Person p;
        int hw1, hw2, hw3, hw4, hw5, exam;
        if (!(iss >> p.firstName >> p.lastName >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam))
            continue;

        p.homework = {hw1, hw2, hw3, hw4, hw5};
        p.examResults = exam;

        double finalAvg = p.averagePath();
        if (finalAvg >= 5.0) {
            goodOut << p.firstName << ' ' << p.lastName << ' ' << std::fixed << std::setprecision(2) << finalAvg << '\n';
        } else {
            badOut << p.firstName << ' ' << p.lastName << ' ' << std::fixed << std::setprecision(2) << finalAvg << '\n';
        }
    }
}
