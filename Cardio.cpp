#include "Cardio.h"
#include <iostream>

using namespace std;

Cardio::Cardio(string n, int d)
    : Exercise(n), duration(d) {}

double Cardio::calculateVolume() {
    return duration;
}

void Cardio::print() const {
    cout << "Cardio: " << name << " duration: " << duration << endl;
}

string Cardio::getType() const {
    return "C";
}