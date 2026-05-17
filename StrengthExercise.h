#ifndef STRENGTH_H
#define STRENGTH_H

#include "Exercise.h"

class StrengthExercise : public Exercise {
private:
    double weight;
    int reps;

public:
    StrengthExercise(string n, double w, int r);

    double calculateVolume() override;
    void print() override;
};

#endif