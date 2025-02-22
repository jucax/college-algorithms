#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

class StudentGrades {
public:
    // Syllabus variables
        // Individual Score Variables
        double perrusalPoints = 0.0, participationPoints = 0.0, algorithmsAppPoints = 0.0, interviewPoints = 0.0, extraCreditPoints = 0.0;

        // Exams points
        double textExam1Points = 0.0, textExam2Points = 0.0, cppExamPoints = 0.0, finalExamPoints = 0.0, preAssesmentQuestions = 0.0;

        int replacedExam = 0;
        
        // Multiple Score Variables
        // Assignments 
        vector<double> possibleAssignmentsPoints = vector<double>(6, 0.0);
        vector<double> assignmentsPoints = vector<double>(6, 0.0);
        vector<int> ontimeBonus = vector<int>(6, 0);
        vector<int> lateSubmissions = vector<int>(6, 0);

        // Projects
        vector<double> projectsPoints = vector<double>(4, 0.0);
        vector<double> projectPenalties = vector<double>(4, 0.0);
        vector<int> daysLateProjectsSubmissions = vector<int>(4, 0);

    // Final category scores
        double finalPerusall = 0.0;
        double finalParticipation = 0.0;
        double finalAssignments = 0.0;
        double finalProjects = 0.0;
        double finalAlgorithmsApp = 0.0;
        double finalPrerequisiteAssessment = 0.0;
        double finalTextExam1 = 0.0;
        double finalCppExam = 0.0;
        double finalTextExam2 = 0.0;
        double finalInterview = 0.0;
        double finalFinalExam = 0.0;
        double finalBonus = 0.0;

        double finalGrade = 0.0;  
};

// Reading file function
void readFile(string filename, StudentGrades& student) {
    ifstream fin;
    fin.open(filename);

    // Throw error and exit if examplefromdranthony.txt is not found
    if (fin.fail()) {
        cerr << "The file \"examplefromdranthony.txt\" does not exist. Exiting."
                  << endl;
        exit(1);
    }

    // Read and assign values
    fin >> student.perrusalPoints; // Perusall Readings
    fin >> student.participationPoints; // Classroom Participation

    // Read the possible assignment points line of 6 numbers
    for (int i = 0; i < 6; i++) {
        fin >> student.possibleAssignmentsPoints[i];
    }

    // Read the actual assignment points line of 6 numbers
    for (int i = 0; i < 6; i++) {
        fin >> student.assignmentsPoints[i];
    }

    // On time bonus
    fin.ignore();  // Ignore newline before reading full lines

    // 🔹 Read On-Time Bonuses with a 0/1 structure
    string line;
    getline(fin, line);
    stringstream ssBonus(line);
    int bonus;
    while (ssBonus >> bonus) {
        student.ontimeBonus[bonus - 1] = 1; // Convert 1-based to 0-based index
    }

    //Submit late
    getline(fin, line);
    stringstream ssLate(line);
    int late;
    while (ssLate >> late) {
        student.lateSubmissions[late - 1] = 1; // Convert 1-based to 0-based index
    }

    // Read the project points line of 4 numbers
    for (int i = 0; i < 4; i++) {
        fin >> student.projectsPoints[i];
    }
    // Read the numbers of days late for projects line of 4 numbers
    for (int i = 0; i < 4; i++) {
        fin >> student.daysLateProjectsSubmissions[i];
    }

    fin >> student.algorithmsAppPoints; // Evaluation of Algorithms in an App
    fin >> student.preAssesmentQuestions; // Prerequisite Assessment
    fin >> student.textExam1Points; // Textbook Exam 1
    fin >> student.cppExamPoints; // C++ Exam
    fin >> student.textExam2Points; // Textbook Exam 2
    fin >> student.interviewPoints; // Whiteboard Coding Interview
    fin >> student.finalExamPoints; // Final Exam
    fin >> student.extraCreditPoints; // Bonus
}


// Calculate grade function
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
    double totalPointsEarned = 0.0;
    double totalPointsPossible = 0.0;
    double maxPenaltyWaived = 0.0;

    for (int i = 0; i < 6; i++) {
        // Helper variable to calculate the score of each assignment
        double score = student.assignmentsPoints[i]; 

        // Check for on-time bonus
        if (student.ontimeBonus[i] == 1) {
            score += (0.05 * student.assignmentsPoints[i]);
        }
        // Check for late penalty 
        if (student.lateSubmissions[i] == 1) {
            double penalty = score * 0.5;

            // Track the highest penalty to waive
            maxPenaltyWaived = max(maxPenaltyWaived, penalty);

            score -= penalty;
        } 

        totalPointsEarned += score;
        totalPointsPossible += student.possibleAssignmentsPoints[i];
    }

    totalPointsEarned += maxPenaltyWaived;
    student.finalAssignments = (totalPointsEarned / totalPointsPossible) * 12;
    
    
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
    student.finalPrerequisiteAssessment = (student.preAssesmentQuestions * 4) / 10;

    // Total Exams
    student.finalTextExam1 = (student.textExam1Points * 11) / 100;
    student.finalCppExam = (student.cppExamPoints * 11) / 100;
    student.finalTextExam2 = (student.textExam2Points * 11) / 100;
    student.finalFinalExam = (student.finalExamPoints * 18) / 100;

    // Total Whiteboard Coding Interview
    student.finalInterview = (student.interviewPoints * 6) / 12;

    // Grade Replacement


    // Final Grade Calculation
    student.finalGrade = student.finalPerusall + student.finalParticipation + student.finalAssignments +
                         student.finalProjects + student.finalAlgorithmsApp + student.finalPrerequisiteAssessment +
                         student.finalTextExam1 + student.finalCppExam + student.finalTextExam2 +
                         student.finalInterview + student.finalFinalExam + student.extraCreditPoints;
                         
}


// Print final grade function
void printFinalGrades (string filename, StudentGrades& student) {
    cout << "File: " << filename << endl;
    cout << "Perusall Readings: " << student.finalPerusall << endl;
    cout << "Classroom Participation: " << student.finalParticipation << endl;
    cout << "Homework Assignments: " << student.finalAssignments << endl;
    cout << "C++ Projects: " << student.finalProjects << endl;
    cout << "Evaluation of Algorithms in an App: " << student.finalAlgorithmsApp << endl;
    cout << "Prerequisite Assessment: " << student.finalPrerequisiteAssessment << endl;
    cout << "Textbook Exam 1: " << student.finalTextExam1 << endl;
    cout << "C++ Exam: " << student.finalCppExam << endl;
    cout << "Textbook Exam 2: " << student.finalTextExam2 << endl;
    cout << "Whiteboard Coding Interview: " << student.finalInterview << endl;
    cout << "Final Exam: " << student.finalFinalExam << endl;
    cout << "Final Exam Grade Replaced: " << endl;
    cout << "Bonus: " << student.extraCreditPoints << endl;
    cout << "Final Grade: " << student.finalGrade << endl;
}

int main() {
    // Create a new Student object
    StudentGrades student;
    string filename = "examplefromdranthony.txt";

    readFile(filename, student);
    calculateGrade(student);
    printFinalGrades(filename, student);
}
    