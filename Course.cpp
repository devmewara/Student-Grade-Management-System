#include "Course.h"
#include <algorithm>
#include <iomanip>

using namespace std;

Course::Course(string courseName) {
    this->courseName = courseName;
}

void Course::addStudent(const Student& student) {
    for (const Student& s : students) {
        if (s.getRollNo() == student.getRollNo()) {
            cout << "\nStudent with Roll No. "
                 << student.getRollNo()
                 << " already exists.\n";
            return;
        }
    }

    students.push_back(student);
}

void Course::sortByRank() {

    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.getTotal() > b.getTotal();
        });

}

void Course::printReport() const {

    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\n===============================================================\n";
    cout << "                     " << courseName << endl;
    cout << "===============================================================\n";

    cout << left
         << setw(8) << "Roll"
         << setw(18) << "Name"
         << setw(8) << "Total"
         << setw(10) << "Average"
         << setw(8) << "Grade"
         << endl;

    cout << "---------------------------------------------------------------\n";

    for (const Student& s : students)
        cout << s << endl;

    cout << "===============================================================\n";
}

void Course::topN(int n) const {

    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    int limit = min(n, (int)students.size());

    cout << "\nTop " << limit << " Students\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < limit; i++) {
        cout << i + 1 << ". "
             << students[i].getName()
             << " (Roll: " << students[i].getRollNo()
             << ", Total: " << students[i].getTotal()
             << ")\n";
    }
}

void Course::searchStudent(int rollNo) const {

    for (const Student& s : students) {
        if (s.getRollNo() == rollNo) {

            cout << "\nStudent Found\n";
            cout << "---------------------------------------------\n";

            cout << left
                 << setw(8) << "Roll"
                 << setw(18) << "Name"
                 << setw(8) << "Total"
                 << setw(10) << "Average"
                 << setw(8) << "Grade"
                 << endl;

            cout << s << endl;
            return;
        }
    }

    cout << "\nStudent not found.\n";
}

void Course::removeStudent(int rollNo) {

    for (auto it = students.begin(); it != students.end(); it++) {

        if (it->getRollNo() == rollNo) {

            students.erase(it);

            cout << "\nStudent removed successfully.\n";

            return;
        }
    }

    cout << "\nStudent not found.\n";
}