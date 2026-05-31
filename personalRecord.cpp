#include "PersonalRecord.h"
#include <iostream>

using namespace std;

PersonalRecord::PersonalRecord(string name, double weight) {
    exerciseName = name;
    bestWeight = weight;
}

void PersonalRecord::update(double newWeight) {
    if (newWeight > bestWeight) {
        bestWeight = newWeight;
    }
}

void PersonalRecord::print() const {
    cout << exerciseName << " PR: " << bestWeight << " kg" << endl;
}

string PersonalRecord::getName() const {
    return exerciseName;
}