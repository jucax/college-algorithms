ALGORITHMS PROJECT 2 README
Student:
    Juan Martinez

Files submitted:
    - main.cpp - Main program file containing the implementation of the grade calculator.
    - examplefromdranthony.txt - Example test file containing sample student grades.
    - allZeroes.txt - Test file where all grades are set to zero.
    - test1.txt - Test file with perfect scores in all categories.
    - test2.txt - Test file including all late penalties and some assignments with zero scores.
    - test3.txt - Test file with varying late days for projects to evaluate penalty application.
    - test4.txt - Test case where all timed assessments have the same percentage, lower than the final exam. The program should replace Textbook Exam 1, as it provides the greatest benefit and is the first in the ordered list.
    - test5.txt - Test case where the Prerequisite Assessment has a lower percentage than the C++ Exam, but both are lower than the final exam percentage. The program should replace C++ Exam since it has more points lost, resulting in a higher benefit for the student.
    - test6.txt - Test file simulating a different student's grades, where Textbook Exam 2 is replaced due to a lower percentage than the final exam. This file also contains multiple blank spaces and tabs to test input reading robustness.
    - test7.txt - Test file verifying that values fall within their specified ranges. This includes out-of-range inputs, such as a Perusall score of 6, negative participation points, score above 100 for Algorithms in an App and a Whiteboard Interview score of -1. Since the Whiteboard Interview score would be counted as 0, the program should replace it with the Final Exam percentage following the grade replacement logic.

High-Level Overview:
    1. readFile function
        This function reads a structured data file containing student grades and stores the values in a StudentGrades object. The file follows a strict format to read each component of the final grade. It also accounts for on-time bonuses and late penalties by processing assignment submissions.

        It stores individual score components in variables, and multiple score components such as assignments and projects in vectors.
        To handle on-time bonuses and late submissions, the function reads space-separated indices and converts them from 1-based to 0-based indexing, storing them in vectors for efficient access. 

        Efficiency Considerations:
            - Time Complexity: O(n), where n is the number of values in the file. Each value is read sequentially.
            - Space Complexity:  O(1), since data is stored in a fixed-structure StudentGrades object without dynamic memory allocation.

    2. calculateGrade function
        This function processes all grading components and calculates the final grade for a student based on their points earned. It applies on-time bonuses and late penalties for assignments, penalties per late day for projects, and weights each category based on the course grading structure.

        Additionally, it determines if the final exam should replace any of the timed assessment. If the final exam is not the one with the lowest percentage, the function calls replaceGrade() to find the assesment to be replaced and make the adjustment.

        Efficiency Considerations:
            - Time Complexity: O(1), since all calculations involve a fixed number of operations overa constant set of grades.
            - Space Complexity:  O(1), since it only updates the existing StudentGrades object.

    3. replaceGrade function
        This function determines which of the timed assessments should be replaced by the Final Exam score. It finds the assessment where the student lost the most points and checks if the Final Exam has a higher percentage, if the percentage is lower, look for the next best option, if it is higher then updates the corresponding grade and records the replaced assessment to display it later in the final report. 

        Efficiency Considerations:
            - Time Complexity: O(1), since it performs a fixed number of comparisons and updates.
            - Space Complexity: O(1), since it modifies the existing StudentGrades object without allocating new memory.

    4. printFinalGrades function
        This function prints a final report that includes the name of the file where the data was collected, the name of all components along with the grade obtained and the final score. It ensures values are displayed with four decimal places.

        Additionally, it prints the assessment that was replaced (if any), ensuring clear and consistent output.

        Efficiency Considerations:
            - Time Complexity: O(1), since it prints a fixed number of values.
            - Space Complexity: O(1), since it does not store additional data.

Known Limitations:
    I believe my code fully meets the requirements of the assignment for an input that follows the specifications outlined in the project description.

Test Cases:
    1.  Input: examplefromdranthony.txt
        2.8
        90
        42 45 40 40 46 44
        38 40 40 25 39 40
        2 3
        4
        95 80 92 100
        0 0 2 0
        96
        9
        104
        95
        90
        11
        88
        0.5
        Output: 
        File: examplefromdranthony.txt
        Perusall Readings: 4.0000
        Classroom Participation: 2.7000
        Homework Assignments: 10.5525
        C++ Projects: 9.9060
        Evaluation of Algorithms in an App: 7.6800
        Prerequisite Assessment: 3.6000
        Textbook Exam 1: 11.4400
        C++ Exam: 10.4500
        Textbook Exam 2: 9.9000
        Whiteboard Coding Interview: 5.5000
        Final Exam: 15.8400
        Final Exam Grade Replaced: None
        Bonus: 0.5000
        Final Grade: 92.0685
        Why?: Ensures that a standard dataset with varied scores across all grading components is processed correctly

    2.  Input: allZeroes.txt
        0.00
        0
        42 45 40 40 46 44
        0 0 0 0 0 0


        0 0 0 0 
        0 0 0 0
        0
        0
        0
        0
        0
        0
        0
        0
        Output: 
        File: allZeroes.txt
        Perusall Readings: 0.0000
        Classroom Participation: 0.0000
        Homework Assignments: 0.0000
        C++ Projects: 0.0000
        Evaluation of Algorithms in an App: 0.0000
        Prerequisite Assessment: 0.0000
        Textbook Exam 1: 0.0000
        C++ Exam: 0.0000
        Textbook Exam 2: 0.0000
        Whiteboard Coding Interview: 0.0000
        Final Exam: 0.0000
        Final Exam Grade Replaced: None
        Bonus: 0.0000
        Final Grade: 0.0000
        Why?: Ensures correct handling of a case where the student has no grades, validating output formatting.

    3.  Input: test1.txt
        3
        100.0
        42 45 40 40 46 44
        42 45 40 40 46 44


        100 100 100 100
        0 0 0 0
        100.0
        10
        100.0
        100.0
        100.0
        12
        100.0
        0
        Output:
        File: test1.txt
        Perusall Readings: 4.0000
        Classroom Participation: 3.0000
        Homework Assignments: 12.0000
        C++ Projects: 12.0000
        Evaluation of Algorithms in an App: 8.0000
        Prerequisite Assessment: 4.0000
        Textbook Exam 1: 11.0000
        C++ Exam: 11.0000
        Textbook Exam 2: 11.0000
        Whiteboard Coding Interview: 6.0000
        Final Exam: 18.0000
        Final Exam Grade Replaced: None
        Bonus: 0.0000
        Final Grade: 100.0000
        Why?: Ensures correct handling of maximum scores across all components.

    4.  Input: test2.txt
        3
        100.0
        42 45 40 40 46 44
        42 0 40 40 0 44

        1 2 3 4 5 6
        100 100 100 100
        0 0 0 0
        100.0
        10
        100.0
        100.0
        100.0
        12
        100.0
        0
        Output:
        File: test2.txt
        Perusall Readings: 4.0000
        Classroom Participation: 3.0000
        Homework Assignments: 4.9027
        C++ Projects: 12.0000
        Evaluation of Algorithms in an App: 8.0000
        Prerequisite Assessment: 4.0000
        Textbook Exam 1: 11.0000
        C++ Exam: 11.0000
        Textbook Exam 2: 11.0000
        Whiteboard Coding Interview: 6.0000
        Final Exam: 18.0000
        Final Exam Grade Replaced: None
        Bonus: 0.0000
        Final Grade: 92.9027
        Why?: Test file including all late penalties and some assignments with zero scores. Ensures proper deduction of late penalties in assingments and correct handling of missing scores.

    5.  Input: test3.txt
        3
        100.0
        42 45 40 40 46 44
        42 45 40 40 46 44


        100 100 100 100
        0 4 5 6
        100.0
        10
        100.0
        100.0
        100.0
        12
        100.0
        0
        Output:
        File: test3.txt
        Perusall Readings: 4.0000
        Classroom Participation: 3.0000
        Homework Assignments: 12.0000
        C++ Projects: 3.6000
        Evaluation of Algorithms in an App: 8.0000
        Prerequisite Assessment: 4.0000
        Textbook Exam 1: 11.0000
        C++ Exam: 11.0000
        Textbook Exam 2: 11.0000
        Whiteboard Coding Interview: 6.0000
        Final Exam: 18.0000
        Final Exam Grade Replaced: None
        Bonus: 0.0000
        Final Grade: 91.6000
        Why?: Test file with varying late days for projects to evaluate penalty application. Ensures that late project submission penalties are applied correctly according to the given rules.

    6.  Input: test4.txt
        3
        100.0
        42 45 40 40 46 44
        42 45 40 40 46 44


        100 100 100 100
        0 0 0 0
        100.0
        7.5
        75.0
        75.0
        75.0
        9
        100.0
        0
        Output:
        File: test4.txt
        Perusall Readings: 4.0000
        Classroom Participation: 3.0000
        Homework Assignments: 12.0000
        C++ Projects: 12.0000
        Evaluation of Algorithms in an App: 8.0000
        Prerequisite Assessment: 3.0000
        Textbook Exam 1: 11.0000
        C++ Exam: 8.2500
        Textbook Exam 2: 8.2500
        Whiteboard Coding Interview: 4.5000
        Final Exam: 18.0000
        Final Exam Grade Replaced: Textbook Exam 1
        Bonus: 0.0000
        Final Grade: 92.0000
        Why?: Test case where all timed assessments have the same percentage, lower than the final exam. The program should replace Textbook Exam 1, as it provides the greatest benefit and is the first in the ordered list.

    7.  Input: test5.txt
        3
        100.0
        42 45 40 40 46 44
        42 45 40 40 46 44


        100 100 100 100
        0 0 0 0
        100.0
        6
        75.0
        70.0
        75.0
        9
        100.0
        0
        Output:
        File: test5.txt
        Perusall Readings: 4.0000
        Classroom Participation: 3.0000
        Homework Assignments: 12.0000
        C++ Projects: 12.0000
        Evaluation of Algorithms in an App: 8.0000
        Prerequisite Assessment: 2.4000
        Textbook Exam 1: 8.2500
        C++ Exam: 11.0000
        Textbook Exam 2: 8.2500
        Whiteboard Coding Interview: 4.5000
        Final Exam: 18.0000
        Final Exam Grade Replaced: C++ Exam
        Bonus: 0.0000
        Final Grade: 91.4000
        Why?: Test case where the Prerequisite Assessment has a lower percentage than the C++ Exam, but both are lower than the final exam percentage. The program should replace the C++ Exam since it results in the highest grade increase.

    8.  Input: test6.txt
        2
        90.0
        42   45     40 40   46          44
        38	40	 20	   23	40	35
        2 4     6
            1 3   5
        95	80	92	100
        0 2         1 0
        96.0
        9
        100.0
        90.0
        89.0
        11
        90.0
        0.5
        Output:
        File: test6.txt
        Perusall Readings: 3.0000
        Classroom Participation: 2.7000
        Homework Assignments: 8.0265
        C++ Projects: 9.4980
        Evaluation of Algorithms in an App: 7.6800
        Prerequisite Assessment: 3.6000
        Textbook Exam 1: 11.0000
        C++ Exam: 9.9000
        Textbook Exam 2: 9.9000
        Whiteboard Coding Interview: 5.5000
        Final Exam: 16.2000
        Final Exam Grade Replaced: Textbook Exam 2
        Bonus: 0.5000
        Final Grade: 87.5045
        Why?: Test file simulating a different student's grades, where Textbook Exam 2 is replaced due to a lower percentage than the final exam. This file also contains multiple blank spaces and tabs to test input reading robustness.

    9.  Input: test7.txt
        6
        -10.0
        42 45 40 40 46 44
        42 45 40 40 46 44


        100 100 100 100
        0 0 0 0
        120.0
        10
        100.0
        100.0
        100.0
        -1
        100.0
        0
        Output:
        File: test7.txt
        Perusall Readings: 4.0000
        Classroom Participation: 0.0000
        Homework Assignments: 12.0000
        C++ Projects: 12.0000
        Evaluation of Algorithms in an App: 8.0000
        Prerequisite Assessment: 4.0000
        Textbook Exam 1: 11.0000
        C++ Exam: 11.0000
        Textbook Exam 2: 11.0000
        Whiteboard Coding Interview: 6.0000
        Final Exam: 18.0000
        Final Exam Grade Replaced: Whiteboard Coding Interview
        Bonus: 0.0000
        Final Grade: 97.0000
        Why?: Test file verifying that values fall within their specified ranges. This includes out-of-range inputs such as a Perusall score of 6, negative participation points, scores above 100 for Algorithms in an App, and a Whiteboard Interview score of -1. The Whiteboard Interview score should be counted as 0, and the program should replace it with the Final Exam percentage following the grade replacement logic.