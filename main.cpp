#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

int main() {

    Course course("Semester Result - B.Tech CSE");

    vector<string> subjects = {
        "English",
        "Math",
        "Science",
        "Computer Science",
        "General Knowledge"
    };

    int choice;

    cout << "=====================================\n";
    cout << "   GRADECORE - Result Management\n";
    cout << "=====================================\n";

    do {

        cout << "\n========== MENU ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display Report\n";
        cout << "3. Show Top N Students\n";
        cout << "4. Search Student\n";
        cout << "5. Remove Student\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {

            int roll;
            string name;
            vector<int> marks;

            cout << "\nEnter Roll Number: ";
            cin >> roll;

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            for (string subject : subjects) {

                int mark;

                cout << "Enter " << subject << " Marks: ";
                cin >> mark;

                marks.push_back(mark);
            }

            Student s(roll, name, marks);

            course.addStudent(s);

            course.sortByRank();

            cout << "\nStudent Added Successfully.\n";

            break;
        }

        case 2:

            course.printReport();

            break;

        case 3: {

            int n;

            cout << "Enter N: ";
            cin >> n;

            course.topN(n);

            break;
        }

        case 4: {

            int roll;

            cout << "Enter Roll Number: ";
            cin >> roll;

            course.searchStudent(roll);

            break;
        }

        case 5: {

            int roll;

            cout << "Enter Roll Number: ";
            cin >> roll;

            course.removeStudent(roll);

            break;
        }

        case 0:

            cout << "\nThank You!\n";

            break;

        default:

            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 0);

    return 0;
}