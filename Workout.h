#ifndef WORKOUT_H
#define WORKOUT_H

#include <vector>
#include "Exercise.h"

class Workout {
private:
    vector<Exercise*> exercises;

public:
    void addExercise(Exercise* e);
    void showWorkout() const;
};

#endif