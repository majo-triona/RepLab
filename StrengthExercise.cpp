#include "StrengthExercise.h"
#include <iostream>

using namespace std;

StrengthExercise::StrengthExercise(string n, double w, int r)
    : Exercise(n), weight(w), reps(r) {}

double StrengthExercise::calculateVolume() const {
    return weight * reps;
}

void StrengthExercise::print() const {
    cout << "Strength: " << name
         << " | Weight: " << weight
         << " | Reps: " << reps
         << " | Volume: " << calculateVolume()
         << endl;
}

double StrengthExercise::getWeight() const {
    return weight;
}

int StrengthExercise::getReps() const {
    return reps;
}

string StrengthExercise::getType() const {
    return "S";
}