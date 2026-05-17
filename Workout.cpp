#include "Workout.h"
#include <iostream>

void Workout::addExercise(Exercise* e) {
    exercises.push_back(e);
}

void Workout::showWorkout() const {
    cout << "\n===== WORKOUT =====\n";
    for (auto e : exercises) {
        e->print();
        cout << "-------------------\n";
    }
    cout << "===================\n";
}