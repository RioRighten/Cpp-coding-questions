#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int id;
    double grade;
};

bool compareGrades(const Student& s1, const Student& s2) {
    return s1.grade > s2.grade;
}

int main() {
    vector<Student> students = {{"Alice", 1, 90}, {"Bob", 2, 85}, {"Charlie", 3, 95}};
    sort(students.begin(), students.end(), compareGrades);

    for (const auto& student : students) {
        cout << student.name << " - " << student.grade << endl;
    }
    return 0;
}
