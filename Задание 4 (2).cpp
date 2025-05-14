#include <iostream>
#include <cmath>
using namespace std;

/**
* @brief Считывает значения с клавиатуры с проверкой ввода
* @return возвращает значение, если оно правильное, иначе завершает программу
*/
double getValue();

/**
* @brief Функция для вычисления значения функции y = cos(2/x) - 2*sin(1/x) + 1/x
* @return cos(2/x) - 2*sin(1/x) + 1/x
*/
double calculate_expression(const double x);

/**
* @brief Функция для проверки, что шаг положительный
* @return положительный шаг
*/
double getPositiveStep();

/**
* @brief Запрашивает у пользователя ввод положительного значения x,
* и продолжает запрашивать значение до тех пор, пока не будет введено положительное число.
* @return Возвращает введенное положительное значение x.
*/
double getPositiveX();

/**
* @brief Функция для проверки, что значение x входит в область определения функции (ООФ)
* @param x значение x
* @return true, если x входит в ООФ, иначе false
*/
bool isOOF(double x);

/**
* @brief Точка входа в программу
* @return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите начальное значение x: ";
    double startX = getPositiveX();

    cout << "Введите конечное значение x: ";
    double endX = getPositiveX();

    double step = getPositiveStep();

    cout << "x | y" << endl;
    cout << "--------" << endl;

    for (double x = startX; x <= endX; x += step)
    {
        if (isOOF(x))
        {
            double y = calculate_expression(x);
            cout << x << " | " << y << endl;
        }
        else
        {
            cout << x << " | Функция не определена" << endl;
        }
    }

    return 0;
}

double getValue()
{
    double value=0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

double calculate_expression(const double x) {
    return cos(2.0 / x) - 2.0 * sin(1.0 / x) + 1.0 / x;
}

double getPositiveStep()
{
    double step=0;
    do {
        cout << "Введите положительный шаг: ";
        step = getValue();
        if (step <= 0)
        {
            cout << "Ошибка. Шаг должен быть положительным. Повторите ввод." << endl;
        }
    } while (step <= 0);
    return step;
}

double getPositiveX()
{
    double x=0;
    do {
        cout << "Введите положительное значение x: ";
        x = getValue();
        if (x <= 0)
        {
            cout << "Ошибка. X должно быть положительным. Повторите ввод." << endl;
        }
    } while (x <= 0);
    return x;
}

bool isOOF(double x)
{
    return x != 0.0;
}
