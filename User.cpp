#include "User.h"
#include <iostream>
#include <stdexcept>

using namespace std;

User::User(string n, int a, double w, double h)
    : Person(n, a), weight(w), height(h) {

    if (a <= 0)
        throw invalid_argument("Age must be positive");

    if (w <= 0)
        throw invalid_argument("Weight must be positive");

    if (h <= 0)
        throw invalid_argument("Height must be positive");
}

void User::showUser() const {
    cout << "User: " << name << " Age: " << age << endl;
}

void User::addWorkout(Workout* w) {
    workouts.push_back(w);
}

void User::showWorkoutHistory() const {
    cout << "\nWorkout history:\n";
    for (size_t i = 0; i < workouts.size(); i++) {
        cout << workouts[i]->getDate() << endl;
    }
}

void User::updateRecord(string exerciseName, double weightValue) {
    bool found = false;

    for (auto &r : records) {
        if (r.getName() == exerciseName) {
            r.update(weightValue);
            found = true;
            break;
        }
    }

    if (!found) {
        PersonalRecord newRecord(exerciseName, weightValue);
        records.push_back(newRecord);
    }
}

void User::showRecords() const {
    cout << "\nPersonal Records:\n";
    for (auto &r : records) {
        r.print();
    }
}