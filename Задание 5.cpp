#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Вычисляет сумму членов последовательности от 1 до n.
 * @param n Положительное целое число.
 * @return Сумма членов последовательности как double.
 */
double sumIntegral(const int n);

/**
 * @brief Вычисляет факториал числа k.
 * @param k Целое число.
 * @return Факториал числа k как double.
 */
double factorial(const int k);

/**
 * @brief Проверяет корректность ввода значения n.
 * @return Положительное целое число n или -1 в случае ошибки.
 */
int getValidN();

/**
 * @brief Проверяет корректность ввода значения e.
 * @return Неотрицательное число e как double.
 */
double getValidE();

/**
 * @brief Вычисляет сумму первых n членов последовательности.
 * @param n Положительное целое число.
 * @return Сумма первых n членов последовательности как double.
 */
double sumFirstN(const int n);

/**
 * @brief Вычисляет сумму членов последовательности по модулю не меньших e.
 * @param n Положительное целое число.
 * @param e Неотрицательное число.
 * @return Сумма членов по модулю не меньших e как double.
 */
double sumByMagnitude(const int n, const double e);

int main()
{
    setlocale(LC_ALL, "Russian");

    int n = getValidN();
    if (n == -1)
    {
        return 1;
    }

    cout << "Сумма интеграла от k=1 до " << n << " для выражения (-1)^k * k^4 / k!: " 
         << sumIntegral(n) << endl;

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
        return -1;
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
        return 0.0; // Возвращаем 0 как значение по умолчанию
    }

    return e;
}

double factorial(const int k)
{
    if (k == 0 || k == 1) return 1.0;
    
    double result = 1.0;
    for (int i = 2; i <= k; ++i)
    {
        result *= i;
    }
    return result;
}

double sumIntegral(const int n)
{
    return sumFirstN(n);
}

double sumFirstN(const int n)
{
    double sum = 0.0;

    for (int k = 1; k <= n; ++k)
    {
        double term = pow(-1, k) * pow(k, 4) / factorial(k);
        sum += term;
    }

    return sum;
}

double sumByMagnitude(const int n, const double e)
{
    double sum = 0.0;

    for (int k = 1; k <= n; ++k)
    {
        double term = pow(-1, k) * pow(k, 4) / factorial(k);
        if (fabs(term) >= e)
        {
            sum += term;
        }
    }

    return sum;
}