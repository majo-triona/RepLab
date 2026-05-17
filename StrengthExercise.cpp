#include "StrengthExercise.h"
#include <iostream>

StrengthExercise::StrengthExercise(string n, double w, int r)
    : Exercise(n), weight(w), reps(r) {}

double StrengthExercise::calculateVolume() {
    return weight * reps;
}

void StrengthExercise::print() {
    cout << name << " volume: " << calculateVolume() << endl;
}