#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort
#include <string>
using namespace std;

// Class to represent a Student
class Student {
private:
    string name;
    int id;
    float grade;

public:
    Student(const string& n, int i, float g) : name(n), id(i), grade(g) {}

    float getGrade() const {
        return grade;
    }

    void display() const {
        cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << endl;
    }
};

// Comparison function for sorting students based on grades
bool compareByGrade(const Student& a, const Student& b) {
    return a.getGrade() > b.getGrade();  // Sort in descending order
}

int main() {
    vector<Student> students;  // Vector to store student records

    // Input student records
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        string name;
        int id;
        float grade;

        cout << "Enter name, ID, and grade for student " << (i + 1) << ": ";
        cin >> name >> id >> grade;

        students.emplace_back(name, id, grade);  // Add student to the vector
    }

    // Sort students by grade
    sort(students.begin(), students.end(), compareByGrade);

    // Display sorted student records
    cout << "\nSorted Student Records by Grades:\n";
    for (const auto& student : students) {
        student.display();
    }

    return 0;
}
