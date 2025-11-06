<img width="549" height="18" alt="image" src="https://github.com/user-attachments/assets/f36e8cd1-bde9-404e-9e91-2a73a101e0e9" />

/_
Final Points = 0.4 * (Average of HW ⏐ Median of HW) + 0.6 * Exam
This file will contain my task 1, students grades and the median for them.

Changes:

Reorganized the program into multiple source and header files, separating logic into clear units such as person handling, file generation, data splitting, and timing.

Moved class definitions, methods, and supporting types into dedicated header files, with corresponding implementations in separate *.cpp files for cleaner structure and easier maintenance.

Implemented consistent exception handling for file operations, including checks for missing or unreadable input files and failures during output creation.

Added large-scale test data generation capable of producing four files containing 10,000, 100,000, 1,000,000, and 10,000,000 student entries, each using default generated names.

Updated processing logic to categorize students based on final grade: records below 5.0 are written to a “failed” file and those at or above 5.0 to a “passed” file.

Introduced two splitting paths: in-memory processing for small datasets, and a streaming, line-by-line approach for the largest files to avoid excessive memory use.

Included precise timing support using a custom timer class, allowing measurement of key stages such as file generation, reading, processing, and writing.

Ensured that all required structural changes, exception handling mechanisms, and performance analysis capabilities are fully implemented.
_/
