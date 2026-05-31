#include "Workout.h"
#include <iostream>

using namespace std;

Workout::Workout(string date) {
    this->date = date;
}

void Workout::addExercise(Exercise* e) {
    exercises.push_back(e);
}

void Workout::showWorkout() const {
    cout << *this;
}

string Workout::getDate() const {
    return date;
}

void Workout::saveToFile(ofstream& out) const {
    out << date << "\n";
    out << exercises.size() << "\n";
}

void Workout::loadFromFile(ifstream& in) {
    int size;
    getline(in, date);
    in >> size;
    in.ignore();

    exercises.clear();
}

ostream& operator<<(ostream& out, const Workout& w) {
    out << "\n===== WORKOUT =====\n";
    out << "Date: " << w.date << "\n";

    for (auto e : w.exercises) {
        e->print();
        out << "-------------------\n";
    }

    out << "===================\n";

    return out;
}