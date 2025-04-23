#include <iostream>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

double inputPositiveNumber(const string prompt) {
    double number;
    while (true) {
        cout << prompt;
        cin >> number;
        if (cin.fail() || number <= 0) {
            cin.clear();
            cin.ignore();
            cout << "Ошибка ввода! Пожалуйста, введите положительное число." << endl;
        }
        else {
            cin.ignore();
            return number;
        }
    }
}

double calculateTotalDistance(double t1, double v1, double t2, double v2, double t3, double v3) {
    return v1 * t1 + v2 * t2 + v3 * t3;
}

double calculateTimeToHalfDistance(double t1, double v1, double t2, double v2, double t3, double v3) {
    const double totalDistance = calculateTotalDistance(t1, v1, t2, v2, t3, v3);
    const double halfDistance = totalDistance / 2.0;

    double currentDistance = 0.0;
    double time = 0.0;

    const double segment1Distance = v1 * t1;
    if (currentDistance + segment1Distance >= halfDistance) {
        return time + (halfDistance - currentDistance) / v1;
    }
    currentDistance += segment1Distance;
    time += t1;

    const double segment2Distance = v2 * t2;
    if (currentDistance + segment2Distance >= halfDistance) {
        return time + (halfDistance - currentDistance) / v2;
    }
    currentDistance += segment2Distance;
    time += t2;

    return time + (halfDistance - currentDistance) / v3;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Программа расчета времени до первой половины пути" << endl;
    cout << "------------------------------------------------" << endl;

    const double t1 = inputPositiveNumber("Введите время t1 (часы): ");
    const double v1 = inputPositiveNumber("Введите скорость v1 (км/ч): ");
    const double t2 = inputPositiveNumber("Введите время t2 (часы): ");
    const double v2 = inputPositiveNumber("Введите скорость v2 (км/ч): ");
    const double t3 = inputPositiveNumber("Введите время t3 (часы): ");
    const double v3 = inputPositiveNumber("Введите скорость v3 (км/ч): ");

    const double totalDistance = calculateTotalDistance(t1, v1, t2, v2, t3, v3);
    const double timeToHalf = calculateTimeToHalfDistance(t1, v1, t2, v2, t3, v3);
    int choice;

    do {
        cout << "Меню: " << endl;
        cout << "1. Вывести на экран общий путь. " << endl;
        cout << "2. Вывести на экран половину пути. " << endl;
        cout << "3. Вывести на экран время до половины пути. " << endl;
        cout << "4. Выйти из меню. " << endl;
        cout << "Укажите ваш выбор: ";
        cin >> choice;
        switch (choice) {
               case 1: 
                   cout << "Ваш выбор - 1! " << endl;
                   cout << "Общий путь: " << totalDistance << " км" << endl;
                   break;
               case 2:
                   cout << "Ваш выбор - 2! " << endl;
                   cout << "Половина пути: " << totalDistance / 2 << " км" << endl;
                   break;
               case 3:
                   cout << "Ваш выбор - 3! " << endl;
                   cout << "Время до половины пути: " << timeToHalf << " часов" << endl;
                   break;
               case 4:
                   cout << "Ваш выбор - 4! " << endl;
                   cout << "Вы вышли из меню! " << endl;
                   break;
               default:
                   cout << "Выбрано некорректное действие! Попробуйте снова. " << endl;
        }   
    } while (choice != 4);
    return 0;
}