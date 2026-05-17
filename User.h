#ifndef USER_H
#define USER_H

#include "Person.h"
#include <vector>

class Workout;

class User : public Person {
private:
    double weight;
    double height;
    vector<Workout*> workouts;

public:
    User(string n, int a, double w, double h);

    void addWorkout(Workout* w);
    void showUser() const;
};

#endif