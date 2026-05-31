#ifndef WORKOUT_H
#define WORKOUT_H

#include <vector>
#include <string>
#include "Exercise.h"

using namespace std;

class Workout {
private:
    vector<Exercise*> exercises;
    string date;

public:
    Workout(string date = "");

    void addExercise(Exercise* e);
    void showWorkout() const;

    string getDate() const;
};

#endif