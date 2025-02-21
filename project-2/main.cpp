#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class StudentGrades {
public:
    // Syllabus variables
    // Individual Score Variables
    double perrusalPoints = 0.0, participationPoints = 0.0, algorithmsAppPoints = 0.0, interviewPoints = 0.0, extraCreditPoints = 0.0;

    // Exams points
    double textExam1Points = 0.0, textExam2Points = 0.0, cppExamPoints = 0.0, finalExamPoints = 0.0;

    int preAssesmentQuestions = 0, replacedExam = 0;
    
    // Multiple Score Variables
    // Assignments 
    vector<double> possibleAssignmentsPoints{6, 0.0}, assignmentsPoints{6, 0.0};
    vector<int> ontimeBonus{6, 0}, lateSubmissions{6, 0};

    // Projects
    vector<double> projectsPoints{4, 0.0}, projectPenalties{4, 0.0};
    vector<int> daysLateProjectsSubmissions{4, 0};
};

// Reading file function
void readFile(string filename) {
    ifstream fin;
    fin.open(filename);

    // Throw error and exit if examplefromdranthony.txt is not found
    if (fin.fail()) {
        cerr << "The file \"examplefromdranthony.txt\" does not exist. Exiting."
                  << endl;
        exit(1);
    }

    double num;

    while (fin >> num) {
        cout << num << endl;
    }

    fin.close();
}

int main() {
    readFile("examplefromdranthony.txt");
}
    