#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class Course {
private:
    string courseName;
    vector<Student> students;

public:
    Course(string courseName);

    void addStudent(const Student& student);

    void sortByRank();

    void printReport() const;

    void topN(int n) const;

    void searchStudent(int rollNo) const;

    void removeStudent(int rollNo);
};

#endif