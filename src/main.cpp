#include <iostream>
#include <fstream>
#include "../include/User.h"
#include "../include/Workout.h"
#include "../include/StrengthExercise.h"
#include "../include/Cardio.h"

using namespace std;

int main() {

    try {
        string name;
        int age;
        double weight, height;

        cout << "Enter user name: ";
        cin >> name;

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter weight: ";
        cin >> weight;

        cout << "Enter height: ";
        cin >> height;

        User u(name, age, weight, height);

        cout << "User created successfully\n";

        Workout* w1 = new Workout("2026-06-01");

        w1->addExercise(new StrengthExercise("Bench Press", 80, 10));
        w1->addExercise(new Cardio("Running", 30));

        Exercise* found = w1->findExercise("Bench Press");

        if (found != nullptr) {
            cout << "\nFound exercise:\n";
            found->print();
        }
        else {
            cout << "\nExercise not found\n";
        }

        u.addWorkout(w1);
        u.weeklySummary();

        cout << *w1;

        ofstream out("workout.txt");
        if (out.is_open()) {
            w1->saveToFile(out);
            out.close();
        }

        cout << "Workout saved to file!\n";

        Workout* w2 = new Workout();

        ifstream in("workout.txt");
        if (in.is_open()) {
            w2->loadFromFile(in);
            in.close();
        }

        cout << "\nLoaded workout from file:\n";
        cout << *w2;

        delete w1;
        delete w2;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}