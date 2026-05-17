#include "User.h"
#include "Workout.h"
#include <iostream>

User::User(string n, int a, double w, double h)
    : Person(n, a), weight(w), height(h) {}

void User::addWorkout(Workout* w) {
    workouts.push_back(w);
}

void User::showUser() const {
    cout << "User: " << name << ", Age: " << age << endl;
}