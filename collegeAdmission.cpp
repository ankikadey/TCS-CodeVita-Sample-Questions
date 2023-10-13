#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Student {
    string id;
    double percentage;
    vector<string> choices;
};

struct College {
    string name;
    int seats;
    vector<Student> admittedStudents;
};

bool sortByPercentage(const Student &a, const Student &b) {
    if (a.percentage != b.percentage) {
        return a.percentage > b.percentage; // Sort in descending order
    } else {
        return a.id < b.id; // If percentage is tied, sort by student id in ascending order
    }
}

int main() {
    int C, N;
    cin >> C >> N;
    vector<College> colleges;
    for (int i = 0; i < C; i++) {
        int seats;
        cin >> seats;
        colleges.push_back({ "C-" + to_string(i + 1), seats, {} });
    }

    vector<Student> students;
    for (int i = 0; i < N; i++) {
        string id, choice1, choice2, choice3;
        double percentage;
        cin >> id >> percentage >> choice1 >> choice2 >> choice3;
        students.push_back({ id, percentage, { choice1, choice2, choice3 } });
    }

    // Round 1 admissions
    for (auto &student : students) {
        for (const auto &choice : student.choices) {
            for (auto &college : colleges) {
                if (college.name == choice && college.admittedStudents.size() < college.seats) {
                    college.admittedStudents.push_back(student);
                    break;
                }
            }
        }
    }

    // Round 2 admissions
    for (auto &student : students) {
        bool admitted = false;
        for (auto &college : colleges) {
            if (find(student.choices.begin(), student.choices.end(), college.name) != student.choices.end() &&
                college.admittedStudents.size() < college.seats) {
                college.admittedStudents.push_back(student);
                admitted = true;
                break;
            }
        }
        if (admitted) {
            student.choices.clear();
        }
    }

    // Calculate and display cut-off percentages
    map<string, double> cutOffs;
    for (const auto &college : colleges) {
        if (college.admittedStudents.empty()) {
            cutOffs[college.name] = -1;
        } else {
            sort(college.admittedStudents.begin(), college.admittedStudents.end(), sortByPercentage);
            cutOffs[college.name] = college.admittedStudents.back().percentage;
        }
    }

    // Display the cut-off percentages in descending order
    for (const auto &college : colleges) {
        if (cutOffs[college.name] == -1) {
            cout << college.name << " n/a" << endl;
        } else {
            cout << college.name << " " << cutOffs[college.name] << endl;
        }
    }

    return 0;
}
