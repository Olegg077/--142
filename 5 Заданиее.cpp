#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief считывает целое число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
int getValue();

/**
 * @brief считывает вещественное число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
double getDouble();

/**
 * @brief проверяет, что введенное значение удовлетворяет условию n>=1
 * @param n считанное значение
*/
void checkN(const int n);

/**
 * @brief Рассчитывает сумму n первых членов ряда
 * @param n заданное число членов
 * @return сумму n первых членов ряда
*/
double sumN(const int n);

/**
 * @brief Рассчитывает следующий член ряда через рекуррентное выражение
 * @param current текущий член ряда
 * @param k текущий индекс
 * @return следующий член ряда
*/
double getNext(const double current, const int k);

/**
 * @brief проверяет, что введенное значение удовлетворяет условию e>0
 * @param e считанное значение
*/
void checkE(const double e);

/**
 * @brief Рассчитывает сумму первых членов ряда, не меньших по модулю e
 * @param e заданная точность
 * @return сумму первых членов ряда, не меньших по модулю e
*/
double sumE(const double e);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена верно
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число членов ряда для рассчета последовательности: ";
    int n = getValue();
    checkN(n);
    cout << "Сумма " << n << " членов ряда равна " << sumN(n) << endl;

    cout << "Введите погрешность для рассчета последовательности: ";
    double e = getDouble();
    checkE(e);
    cout << "Сумма членов ряда с точностью e равна " << sumE(e) << endl;

    return 0;
}

int getValue()
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Ошибка ввода" << endl;
        abort();
    }
    return value;
}

double getDouble()
{
    double value = 0.0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Ошибка ввода" << endl;
        abort();
    }
    return value;
}

void checkN(const int n)
{
    if (n < 1)
    {
        cout << "Ошибка ввода" << endl;
        abort();
    }
}

double sumN(const int n)
{
    const double first = -1.0; // первый член ряда: (-1)^1 * 1^4 / 1! = -1
    double current = first;
    double result = first;

    for (int k = 2; k <= n; k++) // начинаем со второго члена
    {
        current = getNext(current, k);
        result += current;
    }
    return result;
}

double getNext(const double current, const int k)
{
    return current * (-1.0) * pow(k, 4) / (pow(k - 1, 4) * (k - 1) * k);
}

void checkE(const double e)
{
    if (e <= 0)
    {
        cout << "Ошибка ввода" << endl;
        abort();
    }
}

double sumE(const double e)
{
    const double first = -1.0;
    double current = first;
    double result = 0.0;
    int k = 1;

    while (abs(current) >= e)
    {
        result += current;
     current = getNext(current, k);        
      k++;
   }
    return result;
}