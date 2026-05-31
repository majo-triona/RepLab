#include <iostream>
#include <fstream>
#include "User.h"
#include "Workout.h"
#include "StrengthExercise.h"
#include "Cardio.h"

using namespace std;

int main() {

    try {
        User u("Ivan", 20, 75, 180);

        // User obekta trqbva da se suzdava v konzolata

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