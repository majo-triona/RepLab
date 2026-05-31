#ifndef USER_H
#define USER_H

#include "Person.h"
#include "Workout.h"
#include "PersonalRecord.h"
#include <vector>
#include <string>

using namespace std;

class User : public Person {
private:
    double weight;
    double height;

    vector<Workout*> workouts;
    vector<PersonalRecord> records;

public:
    User(string n, int a, double w, double h);

    void showUser() const;

    void addWorkout(Workout* w);
    void showWorkoutHistory() const;

    void updateRecord(string exerciseName, double weight);
    void showRecords() const;

    void weeklySummary() const;   // NEW
};

#endif