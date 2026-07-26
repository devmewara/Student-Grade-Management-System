#include "Student.h"
#include <iomanip>
using namespace std;

Student::Student(int rollNo, string name, vector<int> marks) {
    this->rollNo = rollNo;
    this->name = name;
    this->marks = marks;
    calculateTotal();
    calculateAverage();
    calculateGrade();
}

void Student::calculateTotal() {
    total = 0;
    for (int mark : marks) {
        total += mark;
    }
}
void Student::calculateAverage() {
    if (marks.empty())
        average = 0;
    else
        average = total / marks.size();
}
void Student::calculateGrade() {
    if (average >= 90)
        grade = "O";
    else if (average >= 80)
        grade = "A+";
    else if (average >= 70)
        grade = "A";
    else if (average >= 60)
        grade = "B+";
    else if (average >= 50)
        grade = "B";
    else if (average>=40)
        grade="C+";
    else if (average>=33)
        grade="C";
    else
        grade = "F";
}
int Student::getRollNo() const {
    return rollNo;
}
string Student::getName() const {
    return name;
}
vector<int> Student::getMarks() const {
    return marks;
}
float Student::getTotal() const {
    return total;
}
float Student::getAverage() const {
    return average;
}
string Student::getGrade() const {
    return grade;
}
void Student::display() const {
    cout << *this;
}
ostream& operator<<(ostream& out, const Student& s) {
    out << left
        << setw(8)  << s.rollNo
        << setw(15) << s.name
        << setw(10) << s.marks[0]   // English
        << setw(8)  << s.marks[1]   // Math
        << setw(10) << s.marks[2]   // Science
        << setw(10) << s.marks[3]   // Computer Science
        << setw(8)  << s.marks[4]   // General Knowledge
        << setw(8)  << s.total
        << setw(10) << fixed << setprecision(2) << s.average
        << setw(8)  << s.grade;
    return out;
}