<img width="549" height="18" alt="image" src="https://github.com/user-attachments/assets/f36e8cd1-bde9-404e-9e91-2a73a101e0e9" />

/_
Final Points = 0.4 * (Average of HW ⏐ Median of HW) + 0.6 * Exam
This file will contain my task 1, students grades and the median for them.

StudentSorter/StudentCalculator v1.0

This program expands the original student-processing task into a clean and modular C++ application using multiple header and source files. The goal of the project is to generate large test datasets, calculate final grades for each student, divide them into “passed” and “failed” groups, and measure the performance of each step.

The program first generates five files containing 1,000; 10,000; 100,000; 1,000,000; and 10,000,000 student records. Students use simple default names such as Name1 Surname1, and all homework and exam results are random values from 1 to 10.

Each of these files is then processed. Students are split into two categories based on their final grade:

passed: final score >= 5.0

failed: final score < 5.0

The processing is done in three ways:

Using an in-memory vector (for smaller datasets).

Using std::list with sorting and writing.

Using std::deque with sorting and writing.
For the largest files (1M and 10M), a streaming method is used, which reads each line one by one instead of loading everything into memory.

A simple Timer class is included to measure the execution time of each main step: reading, sorting, splitting, and writing. This allows easy comparison between different dataset sizes and between different container types (vector, list, deque).

The program also uses basic exception handling. If an input or output file cannot be opened, the program throws an error message instead of crashing silently.

Overall, StudentSorter/StudentCalculato v1.0 provides a clear and structured solution to generating large student datasets, computing their grades, separating them into categories, and analyzing the performance of each processing method.
_/
