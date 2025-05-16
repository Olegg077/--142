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
 * @brief Вычисляет сумму первых n членов последовательности с использованием рекуррентного соотношения.
 * @param n Положительное целое число.
 * @return Сумма первых n членов последовательности как double.
 */
double sumFirstN(const int n);

/**
 * @brief Вычисляет сумму членов последовательности по модулю не меньших e с использованием рекуррентного соотношения.
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
        return 0.0;
    }

    return e;
}

double sumIntegral(const int n)
{
    return sumFirstN(n);
}

double sumFirstN(const int n)
{
    double sum = 0.0;
    double current_term = 0.0;
    double factorial_k = 1.0; // 0! = 1

    for (int k = 1; k <= n; ++k)
    {
        factorial_k *= k; // Вычисляем k! как k*(k-1)!
        current_term = pow(-1, k) * pow(k, 4) / factorial_k;
        sum += current_term;
    }

    return sum;
}

double sumByMagnitude(const int n, const double e)
{
    double sum = 0.0;
    double current_term = 0.0;
    double factorial_k = 1.0; // 0! = 1

    for (int k = 1; k <= n; ++k)
    {
        factorial_k *= k; // Вычисляем k! как k*(k-1)!
        current_term = pow(-1, k) * pow(k, 4) / factorial_k;
        if (fabs(current_term) >= e)
        {
            sum += current_term;
        }
    }

    return sum;
}