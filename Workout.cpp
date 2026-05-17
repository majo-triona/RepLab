#include "Workout.h"
#include <iostream>

void Workout::addExercise(Exercise* e) {
    exercises.push_back(e);
}

void Workout::showWorkout() {
    cout << "Workout:\n";
    for (auto e : exercises) {
        e->print();
    }
}