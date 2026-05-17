#include "User.h"
#include "Workout.h"
#include "StrengthExercise.h"
#include "Cardio.h"

int main() {
    User u("Ivan", 20, 75, 180);

    Workout* w1 = new Workout();

    w1->addExercise(new StrengthExercise("Bench Press", 80, 10));
    w1->addExercise(new Cardio("Running", 30));

    w1->showWorkout();

    return 0;
}