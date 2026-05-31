#ifndef CARDIO_H
#define CARDIO_H

#include "Exercise.h"

class Cardio : public Exercise {
private:
    int duration;

public:
    Cardio(string n, int d);

    double calculateVolume() const override;
    void print() const override;

    string getType() const override;
};

#endif