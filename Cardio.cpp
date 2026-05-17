#include "Cardio.h"
#include <iostream>

Cardio::Cardio(string n, int d)
    : Exercise(n), duration(d) {}

double Cardio::calculateVolume() {
    return duration;
}

void Cardio::print() {
    cout << name << " (Cardio) duration: " << duration << " min" << endl;
}