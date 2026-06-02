#ifndef WORKOUT_H
#define WORKOUT_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
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

    void saveToFile(ofstream& out) const;
    void loadFromFile(ifstream& in);

    Exercise* findExercise(string name) const;

    friend ostream& operator<<(ostream& out, const Workout& w);

    ~Workout();
};

#endif