#ifndef PERSONALRECORD_H
#define PERSONALRECORD_H

#include <string>

using namespace std;

class PersonalRecord {
private:
    string exerciseName;
    double bestWeight;

public:
    PersonalRecord(string name = "", double weight = 0);

    void update(double newWeight);
    void print() const;

    string getName() const;
};

#endif