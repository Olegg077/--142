#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Вычисляет сумму первых n членов последовательности с использованием рекуррентного соотношения
 * @param n Положительное целое число
 * @return Сумма первых n членов последовательности как double
 */
double sumFirstN(const int n);

/**
 * @brief Вычисляет сумму членов последовательности по модулю не меньших e
 * @param n Положительное целое число
 * @param e Неотрицательное число
 * @return Сумма членов по модулю не меньших e как double
 */
double sumByMagnitude(const int n, const double e);

/**
 * @brief Проверяет корректность ввода значения n
 * @return Положительное целое число n или завершает программу при ошибке
 */
int getValidN();

/**
 * @brief Проверяет корректность ввода значения e
 * @return Неотрицательное число e или завершает программу при ошибке
 */
double getValidE();

int main()
{
    setlocale(LC_ALL, "Russian");

    int n = getValidN();
    double e = getValidE();

    cout << "Сумма первых " << n << " членов последовательности: " << sumFirstN(n) << endl;
    cout << "Сумма членов по модулю не меньших " << e << ": " << sumByMagnitude(n, e) << endl;

    return 0;
}

int getValidN()
{
    int n = 0;
    cout << "Введите значение n: ";
    cin >> n;

    if (cin.fail() || n <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: n должно быть положительным числом." << endl;
        abort();
    }

    return n;
}

double getValidE()
{
    double e = 0.0;
    cout << "Введите значение e: ";
    cin >> e;

    if (cin.fail() || e < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: e должно быть неотрицательным числом." << endl;
        abort();
    }

    return e;
}

double sumFirstN(const int n)
{
    double sum = 0.0;
    double current_term = 0.0;
    double denominator = 1.0; // Начальное значение для k=1 (1^4/1! = 1)

    for (int k = 1; k <= n; ++k)
    {
        if (k == 1)
        {
            current_term = -1.0; // (-1)^1 * 1^4 / 1! = -1
        }
        else
        {
            current_term *= -1.0 * pow(k, 4) / (pow(k-1, 4) * k);
        }
        sum += current_term;
    }

    return sum;
}

double sumByMagnitude(const int n, const double e)
{
    double sum = 0.0;
    double current_term = 0.0;
    double denominator = 1.0;

    for (int k = 1; k <= n; ++k)
    {
        if (k == 1)
        {
            current_term = -1.0;
        }
        else
        {
            current_term *= -1.0 * pow(k, 4) / (pow(k-1, 4) * k);
        }
        
        if (fabs(current_term) >= e)
        {
            sum += current_term;
        }
    }

    return sum;
}