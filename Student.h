#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    int rollNo;
    vector<int> marks;      // Marks of 5 subjects

    float total;
    float average;
    string grade;

    void calculateTotal();
    void calculateAverage();
    void calculateGrade();

public:
    Student(int rollNo, string name, vector<int> marks);

    int getRollNo() const;
    string getName() const;
    vector<int> getMarks() const;

    float getTotal() const;
    float getAverage() const;
    string getGrade() const;

    void display() const;

    friend ostream& operator<<(ostream& out, const Student& s);
};

#endif