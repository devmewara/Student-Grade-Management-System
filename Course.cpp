#include "Course.h"
#include <algorithm>
#include <iomanip>
using namespace std;

// Comparison function for sorting by average
bool compareStudents(const Student& a, const Student& b) {
    if (a.getAverage() == b.getAverage()) {
        return a.getRollNo() < b.getRollNo();
    }
    return a.getAverage() > b.getAverage();
}

Course::Course(string courseName) {
    this->courseName = courseName;
}

void Course::addStudent(const Student& student) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getRollNo() == student.getRollNo()) {
            cout << "\nStudent with Roll No. "
                 << student.getRollNo()
                 << " already exists.\n";
            return;
        }
    }
    students.push_back(student);
}
void Course::sortByRank() {
    sort(students.begin(), students.end(), compareStudents);
}
void Course::printReport() const {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }
    cout << "\n====================================================================================================\n";
    cout << "                                     " << courseName << endl;
    cout << "====================================================================================================\n";
    cout << left
         << setw(8)  << "Roll"
         << setw(15) << "Name"
         << setw(10) << "English"
         << setw(8)  << "Math"
         << setw(10) << "Science"
         << setw(10) << "Computer"
         << setw(8)  << "GK"
         << setw(8)  << "Total"
         << setw(10) << "Average"
         << setw(8)  << "Grade"
         << endl;
    cout << "----------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < students.size(); i++) {
        cout << students[i] << endl;
    }
    cout << "====================================================================================================\n";
}
void Course::topN(int n) const {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }
    int limit;
    if (n > students.size())
        limit = students.size();
    else
        limit = n;
    cout << "\n====================== TOP " << limit << " STUDENTS ======================\n\n";
    cout << left
         << setw(6)  << "Rank"
         << setw(8)  << "Roll"
         << setw(18) << "Name"
         << setw(10) << "Total"
         << setw(10) << "Average"
         << setw(8)  << "Grade"
         << endl;
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < limit; i++) {
        cout << left
             << setw(6)  << i + 1
             << setw(8)  << students[i].getRollNo()
             << setw(18) << students[i].getName()
             << setw(10) << students[i].getTotal()
             << setw(10) << fixed << setprecision(2) << students[i].getAverage()
             << setw(8)  << students[i].getGrade()
             << endl;
    }
    cout << "---------------------------------------------------------------\n";
}
void Course::searchStudent(int rollNo) const {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getRollNo() == rollNo) {
            cout << "\nStudent Found\n";
            cout << "--------------------------------------------------------------------------------------\n";
            cout << left
            << setw(8)  << "Roll"
            << setw(15) << "Name"
            << setw(10) << "English"
            << setw(8)  << "Math"
            << setw(10) << "Science"
            << setw(10) << "Computer"
            << setw(8)  << "GK"
            << setw(8)  << "Total"
            << setw(10) << "Average"
            << setw(8)  << "Grade"
            << endl;
            cout << "----------------------------------------------------------------------------------------------\n";
            cout << students[i] << endl;
            return;
        }
    }
    cout << "\nStudent not found.\n";
}
void Course::removeStudent(int rollNo) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getRollNo() == rollNo) {
            students.erase(students.begin() + i);
            cout << "\nStudent removed successfully.\n";
            return;
        }
    }
    cout << "\nStudent not found.\n";
}