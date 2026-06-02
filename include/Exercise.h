#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>

using namespace std;

class Exercise {
protected:
    string name;

public:
    Exercise(string n) : name(n) {}

    virtual double calculateVolume() const = 0;
    virtual void print() const = 0;

    string getName() const {
        return name;
    }

    virtual string getType() const = 0;

    virtual ~Exercise() {}
};

#endif