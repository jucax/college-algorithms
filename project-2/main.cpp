#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

class StudentGrades {
public:
    // Syllabus variables
        // Individual Score Variables
        double perrusalPoints = 0.0, participationPoints = 0.0, algorithmsAppPoints = 0.0, interviewPoints = 0.0, extraCreditPoints = 0.0;

        // Exams points
        double prereqAssesmentQuestions = 0.0, textExam1Points = 0.0, cppExamPoints = 0.0, textExam2Points = 0.0, finalExamPoints = 0.0;
        
        // Multiple Score Variables
        // Assignments 
        vector<double> possibleAssignmentsPoints = vector<double>(6, 0.0);
        vector<double> assignmentsPoints = vector<double>(6, 0.0);
        vector<int> ontimeBonus = vector<int>(6, 0);
        vector<int> lateSubmissions = vector<int>(6, 0);

        // Projects
        vector<double> projectsPoints = vector<double>(4, 0.0);
        vector<int> daysLateProjectsSubmissions = vector<int>(4, 0);

        // Grade replaced variable
        string gradeReplaced = "None";

    // Final grades 
        double finalPerusall = 0.0;
        double finalParticipation = 0.0;
        double finalAssignments = 0.0;
        double finalProjects = 0.0;
        double finalAlgorithmsApp = 0.0;
        double finalPrereqAssessment = 0.0;
        double finalTextExam1 = 0.0;
        double finalCppExam = 0.0;
        double finalTextExam2 = 0.0;
        double finalInterview = 0.0;
        double finalFinalExam = 0.0;
        double finalBonus = 0.0;

        double finalGrade = 0.0;  
};


/**
 * The readFile function reads a structured text file containing student grades for each element that is part 
 * of the final grade and stores the values into the corresponding variables with in the `StudentGrades` object. 
 * The file must follow a specific format and if the file does not exist or fails to open, the program exits with 
 * an error message.
 *
 * @param filename The name of the text file containing the student grade data.
 * @param student The reference to the StudentGrades object where the data will be stored.
 *
 * @throws Exits the program if the specified file does not exist or cannot be opened.
 */
void readFile(string filename, StudentGrades& student) {
    ifstream fin;
    fin.open(filename);

    // Throw error and exit if examplefromdranthony.txt is not found
    if (fin.fail()) {
        cerr << "The file" << filename << "does not exist. Exiting."
                  << endl;
        exit(1);
    }

    // Read and assign values
    fin >> student.perrusalPoints; // Perusall Readings
    student.perrusalPoints = max(0.0, min(student.perrusalPoints, 3.0)); // Ensure range [0,3]

    fin >> student.participationPoints; // Classroom Participation
    student.participationPoints = max(0.0, min(student.participationPoints, 100.0)); // Ensure range [0,100]

    // Read the possible assignment points, line of 6 numbers
    for (int i = 0; i < 6; i++) {
        fin >> student.possibleAssignmentsPoints[i];
    }

    // Read the actual assignment points, line of 6 numbers
    for (int i = 0; i < 6; i++) {
        fin >> student.assignmentsPoints[i];
    }

    // On time bonus
    fin.ignore();  // Ignore newline before reading full lines

    // Read On-Time Bonuses with a 0|1 structure
    string line;
    getline(fin, line);
    stringstream ssBonus(line);
    int bonus;
    while (ssBonus >> bonus) {
        student.ontimeBonus[bonus - 1] = 1; // Convert 1-based to 0-based index
    }

    // Late penalties
    getline(fin, line);
    stringstream ssLate(line);
    int late;
    while (ssLate >> late) {
        student.lateSubmissions[late - 1] = 1; // Convert 1-based to 0-based index
    }

    // Read the project points, line of 4 numbers
    for (int i = 0; i < 4; i++) {
        fin >> student.projectsPoints[i];
    }
    // Read the number of days late for projects, line of 4 numbers
    for (int i = 0; i < 4; i++) {
        fin >> student.daysLateProjectsSubmissions[i];
    }

    fin >> student.algorithmsAppPoints; // Read grade of algorithms in an app
    student.algorithmsAppPoints = max(0.0, min(student.algorithmsAppPoints, 100.0)); // Ensure range [0,100]

    fin >> student.prereqAssesmentQuestions; // Read grade prerequisite Assessment
    fin >> student.textExam1Points; // Read grade textbook Exam 1
    fin >> student.cppExamPoints; // Read grade C++ Exam
    fin >> student.textExam2Points; // Read grade textbook Exam 2

    fin >> student.interviewPoints; // Read grade whiteboard coding interview
    student.interviewPoints = max(0.0, min(student.interviewPoints, 12.0)); // Ensure range [0,12]

    fin >> student.finalExamPoints; // Read grade final fxam
    fin >> student.extraCreditPoints; // Read bonus points
    student.extraCreditPoints = max(0.0, student.extraCreditPoints); // Ensure no negative extra points
}


/**
 * The replaceGrade function identifies the timed assessment where the student lost the most points to determine
 * which grade would most benefit the student if replaced by the final exam grade. Then it checks if the final exam percentage
 * is higher than the selected timed assessment percentage, if it is, the corresponding assessment grade is updated, 
 * if it is not, try with the following best option.
 *
 * @param student The reference to the StudentGrades object containing the final grades.
 * @param percPrereqAssessment The percentage score of the Prerequisite Assessment.
 * @param percTextExam1 The percentage score of the Textbook Exam 1.
 * @param percCppExam The percentage score of the C++ Exam.
 * @param percTextExam2 The percentage score of the Textbook Exam 2.
 * @param percInterview The percentage score of the Whiteboard Coding Interview.
 * @param percFinalExam The percentage score of the Final Exam.
 */
void replaceGrade (StudentGrades& student, double percPrereqAssessment, double percTextExam1,
                  double percCppExam, double percTextExam2, double percInterview, double percFinalExam) {
    
    // Calculate lost points (higher is worse)
    vector<double> timedAssesments = {
        (4 - student.finalPrereqAssessment),
        (11 - student.finalTextExam1), 
        (11 - student.finalCppExam), 
        (11 - student.finalTextExam2),
        (6 - student.finalInterview) 
    };

    bool gradeChanged = false; // Boolean flag to stop once the grade has changed

    while (!gradeChanged) {
        double maxLost = timedAssesments[0]; // Prerequisite as default
        int indexOfMaxLost = 0;

        // Find the timed assesment where the student lost more points
        for (int i = 1; i < timedAssesments.size(); i++) {
            if (timedAssesments[i] > maxLost) {
                maxLost = timedAssesments[i];
                indexOfMaxLost = i;
            }
        }

        // Find the percentage of the one with the max lost points
        double percentageOfMaxLost = (indexOfMaxLost == 1) ? percTextExam1 :
                                     (indexOfMaxLost == 2) ? percCppExam :
                                     (indexOfMaxLost == 3) ? percTextExam2 :
                                     (indexOfMaxLost == 4) ? percInterview :
                                     percPrereqAssessment; 

        // Check if the percentage is lower than the one on the final 
        if (percFinalExam > percentageOfMaxLost) {
            switch (indexOfMaxLost) {
                case 0: student.finalPrereqAssessment = (percFinalExam / 100) * 4; 
                        student.gradeReplaced = "Prerequisite Assessment";
                break;
                case 1: student.finalTextExam1 = (percFinalExam / 100) * 11; 
                        student.gradeReplaced = "Textbook Exam 1";
                break;
                case 2: student.finalCppExam = (percFinalExam / 100) * 11; 
                        student.gradeReplaced = "C++ Exam";
                break;
                case 3: student.finalTextExam2 = (percFinalExam / 100) * 11; 
                        student.gradeReplaced = "Textbook Exam 2";
                break;
                case 4: student.finalInterview = (percFinalExam / 100) * 6; 
                        student.gradeReplaced = "Whiteboard Coding Interview";
                break;
            }
            gradeChanged = true;
        } else {
            timedAssesments[indexOfMaxLost] = -100; //  Marked as checked
        }
    }
}


/**
 * The calculateGrade function processes the points obtained by the student in each element, applies necessary 
 * penalties and bonuses, and computes the final grade based on the grading structure provided in the syllabus. 
 * It calculates individual weighted contributions from each of the components of the final grade.
 * 
 * The function also determines if the final exam score should replace the lowest timed assessment score
 * and which of the assignments replace in order to benefit the student more.
 *
 * @param student The reference to the StudentGrades object containing points and where the final calculated values will be stored.
 */
void calculateGrade (StudentGrades& student) {
    // Final Perrusal Grade
    if (student.perrusalPoints >= 2.5) {
        student.finalPerusall = 4.0;
    } else if (student.perrusalPoints >= 2.0) {
        student.finalPerusall = 3.0;
    } else if (student.perrusalPoints >= 1.5) {
        student.finalPerusall = 2.0;
    } else if (student.perrusalPoints >= 1.0) {
        student.finalPerusall = 1.0;
    } else {
        student.finalPerusall = 0.0;
    }

    // Final Participation Grade
    student.finalParticipation = (student.participationPoints * 3) / 100;

    //  Final Assignments Grade 
    double totalAssignmentsPointsEarned = 0.0;
    double totalAssignmentsPointsPossible = 0.0;
    double maxAssignmentsPenaltyWaived = 0.0;

    for (int i = 0; i < 6; i++) {
        // Helper variable to calculate the score of each assignment
        double score = student.assignmentsPoints[i]; 

        // Check for on-time bonus
        if (student.ontimeBonus[i] == 1) score += (0.05 * student.assignmentsPoints[i]);

        // Check for late penalty 
        if (student.lateSubmissions[i] == 1) {
            double penalty = score * 0.5;

            // Track the highest penalty to waive
            maxAssignmentsPenaltyWaived = max(maxAssignmentsPenaltyWaived, penalty);

            score -= penalty;
        } 
        totalAssignmentsPointsEarned += score;

        // Calculate possible points
        totalAssignmentsPointsPossible += student.possibleAssignmentsPoints[i];
    }

    // Add the penalty waived to the points earned
    totalAssignmentsPointsEarned += maxAssignmentsPenaltyWaived;

    if (totalAssignmentsPointsPossible > 0) { // Check to avoid division by 0
        student.finalAssignments = (totalAssignmentsPointsEarned / totalAssignmentsPointsPossible) * 12;
    } else {
        student.finalAssignments = 0.0;
    }
    
    // Total Projects Grade
    for (int i = 0; i < 4; i++) {
        double score = (student.projectsPoints[i] * 3) / 100; // Each project contributes with 3 points to the final grade

        // Apply late penalty (20% per late day)
        if (student.daysLateProjectsSubmissions[i] > 0) {
            double penaltyFactor = 1.0 - (0.2 * student.daysLateProjectsSubmissions[i]);
            if (penaltyFactor < 0) penaltyFactor = 0; // Prevent negative scores in case the project were delivered too late
            score *= penaltyFactor;
        }
    
    student.finalProjects += score;
    }

    // Total Algorithms App
    student.finalAlgorithmsApp = (student.algorithmsAppPoints * 8) / 100;

    // Total Prerequisite Assesment
    student.finalPrereqAssessment = (student.prereqAssesmentQuestions * 4) / 10;

    // Total Exams
    student.finalTextExam1 = (student.textExam1Points * 11) / 100;
    student.finalCppExam = (student.cppExamPoints * 11) / 100;
    student.finalTextExam2 = (student.textExam2Points * 11) / 100;
    student.finalFinalExam = (student.finalExamPoints * 18) / 100;

    // Total Whiteboard Coding Interview
    student.finalInterview = (student.interviewPoints * 6) / 12;

    // Grade Replacement
        // Calculate percentage of timed assesments
        double percPrereqAssessment = (student.finalPrereqAssessment / 4) * 100;
        double percTextExam1 = (student.finalTextExam1 / 11) * 100;
        double percCppExam = (student.finalCppExam / 11) * 100;
        double percTextExam2 = (student.finalTextExam2 / 11) * 100;
        double percInterview = (student.finalInterview / 6) * 100;
        double percFinalExam = (student.finalFinalExam / 18) * 100;

        // Calculate minimum percentage of timed assesments
        double minPercentage = min(min(percPrereqAssessment, percTextExam1),
        min(min(percCppExam, percTextExam2), percInterview));

        // Only call replaceGrade() if the final exam is NOT the one with the lowest percentage
        if (percFinalExam > minPercentage) {
            replaceGrade(student, percPrereqAssessment, percTextExam1, percCppExam, percTextExam2, percInterview, percFinalExam);
        }

    // Final Grade Calculation
    student.finalGrade = student.finalPerusall + student.finalParticipation + student.finalAssignments +
                         student.finalProjects + student.finalAlgorithmsApp + student.finalPrereqAssessment +
                         student.finalTextExam1 + student.finalCppExam + student.finalTextExam2 +
                         student.finalInterview + student.finalFinalExam + student.extraCreditPoints;
                         
}


/**
 * @brief Prints the final calculated grades for a student in a formatted manner.
 *
 * The printFinalGrades function prints a final report that contains all the elements and it's contributions 
 * to the final grade, formatted to four decimal places for precision. Additionally, it reports if any grade 
 * component was replaced by the final exam. And print the final grade including all bonuses and penalties.
 *
 * @param filename The name of the text file from which the student's grades were loaded.
 * @param student The reference to the StudentGrades object containing the final grades.
 */
void printFinalGrades (string filename, StudentGrades& student) {
    cout << fixed << setprecision(4);

    cout << "File: " << filename << endl;
    cout << "Perusall Readings: " << student.finalPerusall << endl;
    cout << "Classroom Participation: " << student.finalParticipation << endl;
    cout << "Homework Assignments: " << student.finalAssignments << endl;
    cout << "C++ Projects: " << student.finalProjects << endl;
    cout << "Evaluation of Algorithms in an App: " << student.finalAlgorithmsApp << endl;
    cout << "Prerequisite Assessment: " << student.finalPrereqAssessment << endl;
    cout << "Textbook Exam 1: " << student.finalTextExam1 << endl;
    cout << "C++ Exam: " << student.finalCppExam << endl;
    cout << "Textbook Exam 2: " << student.finalTextExam2 << endl;
    cout << "Whiteboard Coding Interview: " << student.finalInterview << endl;
    cout << "Final Exam: " << student.finalFinalExam << endl;
    cout << "Final Exam Grade Replaced: " << student.gradeReplaced << endl;
    cout << "Bonus: " << student.extraCreditPoints << endl;
    cout << "Final Grade: " << student.finalGrade << endl;
}

/**
 * The main function iterates through a predefined list of filenames, reading student grade data, 
 * calculating final grades, and then printing the results. Each file is processed independently, 
 * ensuring new student data for each iteration.
 */
int main() {
    // Vector to read text files
    vector <string> filenames = {
        "examplefromdranthony.txt",
        "allZeroes.txt",
        "test1.txt",
        "test2.txt",
        "test3.txt",
        "test4.txt",
        "test5.txt",
        "test6.txt",
        "test7.txt",
        "personalGrades.txt"
    };

     for (const string& filename : filenames) {
        StudentGrades student; // Reset student data for each data file

        readFile(filename, student);
        calculateGrade(student);
        printFinalGrades(filename, student);

        cout << "---------------------------------------\n"; // Separator between files
    }
}
    