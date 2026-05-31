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
        out << e->getType() << "\n";
        out << e->getName() << "\n";

        if (e->getType() == "S") {
            const auto* se = dynamic_cast<const StrengthExercise*>(e);
            out << se->getWeight() << " " << se->getReps() << "\n";
        } else if (e->getType() == "C") {
            const auto* ce = dynamic_cast<const Cardio*>(e);
            out << ce->getDuration() << "\n";
        }
    }
}

void Workout::loadFromFile(ifstream& in) {
    int size;
    getline(in, date);
    in >> size;
    in.ignore();

    for (auto e : exercises) {
        delete e;
    }
    exercises.clear();

    for (int i = 0; i < size; i++) {
        string type;
        string name;

        getline(in, type);
        getline(in, name);

        if (type == "S") {
            double weight;
            int reps;
            in >> weight >> reps;
            in.ignore();
            exercises.push_back(new StrengthExercise(name, weight, reps));
        } else if (type == "C") {
            int duration;
            in >> duration;
            in.ignore();
            exercises.push_back(new Cardio(name, duration));
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

Workout::~Workout() {
    for (int i = 0; i < exercises.size(); i++) {
        delete exercises[i];
    }
    exercises.clear();
}