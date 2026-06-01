# RepLab

## Изисквания
- Windows
- g++ (MSYS2/MinGW) в PATH

## Компилиране
```bash
g++ main.cpp User.cpp Workout.cpp StrengthExercise.cpp Cardio.cpp Person.cpp PersonalRecord.cpp -o app
```

## Стартиране
```bash
.\app
```

## Примерен вход
```
Ivan
22
78.5
180
```

## Бележки
- Програмата записва и чете данни за тренировката от `workout.txt` в папката на проекта.