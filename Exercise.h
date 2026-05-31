#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>

using namespace std;

class Exercise {
protected:
    string name;

public:
    Exercise(string n);
    virtual double calculateVolume() = 0;
    virtual void print() = 0;
    virtual ~Exercise() {}
};

#endif