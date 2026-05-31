#include "Workout.h"
#include "StrengthExercise.h"
#include "Cardio.h"
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

Exercise* Workout::findExercise(string searchName) const {
    for (auto e : exercises) {
        if (e->getName() == searchName) {
            return e;
        }
    }
    return nullptr;
}

void Workout::saveToFile(ofstream& out) const {
    out << date << "\n";
    out << exercises.size() << "\n";

    for (auto e : exercises) {
        out << e->getType() << " " << e->getName() << "\n";
    }
}

void Workout::loadFromFile(ifstream& in) {
    int size;
    getline(in, date);
    in >> size;
    in.ignore();

    exercises.clear();

    for (int i = 0; i < size; i++) {
        string type;
        string name;

        in >> type >> name;
        in.ignore();

        if (type == "S") {
            exercises.push_back(new StrengthExercise(name, 0, 0));
        }
        else if (type == "C") {
            exercises.push_back(new Cardio(name, 0));
        }
    }
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