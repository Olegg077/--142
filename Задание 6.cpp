#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n);

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize();

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const int n);

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, const int min, const int max);

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int* arr, const int n, const int min, const int max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);

/**
 * @brief Заменяет последние k элементов массива на противоположные по знаку.
 * @param arr Указатель на массив целых чисел.
 * @param n Размер массива.
 * @param k Количество последних элементов для замены на противоположные.
 */
void replaceLastKWithOpposite(int* arr, const int n, const size_t k);  // Изменен тип параметра k

/**
 * @brief Выводит индексы элементов массива, которые кратны 3.
 * @param arr Указатель на массив целых чисел.
 * @param n Размер массива.
 */
void printIndicesOfMultiplesOfThree(const int* arr, const int n);

/**
 * @brief Определяет, есть ли пара соседних элементов с заданной суммой.
 * @param arr Указатель на массив целых чисел.
 * @param n Размер массива.
 * @param target Сумма, которую необходимо проверить.
 * @return Индекс первого элемента пары, если пара найдена; -1 в противном случае.
 */
int findPairWithSum(const int* arr, const int n, const int target);  // Добавлен const для target

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main() {
    setlocale(LC_ALL, "Russian");
int n = getSize();
int* arr = new int[n];

cout << "Введите минимальное значение диапазона: ";
int minValue = getNumber();
cout << "Введите максимальное значение диапазона: ";
int maxValue = getNumber();
checkRange(minValue, maxValue);
    cout << "Введите выбор для заполнения массива: " << endl
        << RANDOM << " Для случайного заполнения" << endl
        << MANUALLY << " Для ручного заполнения" << endl;

    int choice = getNumber();

    switch ((enum SELECT)choice) {
    case RANDOM:
        fillArrayRandom(arr, n, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, n, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        delete[] arr; // Освобождаем память перед выходом
        return -1;
    }

    cout << "Элементы массива:" << endl;
    printArray(arr, n);

    // Вызов новых функций
    size_t k;  // Изменен тип переменной
    cout << "Введите количество последних элементов для замены: ";
    k = static_cast<size_t>(getNumber());  // Добавлено приведение типа
    replaceLastKWithOpposite(arr, n, k);

    cout << "Индексы элементов, кратных 3:" << endl;
    printIndicesOfMultiplesOfThree(arr, n);

    int target;
    cout << "Введите целевую сумму для поиска пары: ";
    target = getNumber();
    int pairIndex = findPairWithSum(arr, n, target);

    if (pairIndex != -1) {
        cout << "Найдена пара соседних элементов с суммой " << target
            << " на индексах: " << pairIndex << " и " << pairIndex + 1 << endl;
    }
    else {
        cout << "Пара соседних элементов с суммой " << target << " не найдена." << endl;
    }

    delete[] arr;

    return 0;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Неправильный размер массива" << endl;
        abort();
    }
}

size_t getSize()
{
    cout << "Введите размер массива: ";
    int n = 0; // Инициализация переменной
    cin >> n;
    checkN(n);
    return (size_t)n;
}

int getNumber()
{
    int number = 0; // Инициализация переменной
    cin >> number;
    if (cin.fail())
    {
        cout << "Неправильный ввод данных";
        abort();
    }
    return number;
}

void printArray(const int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

void fillArrayRandom(int* arr, const int n, const int min, const int max)
{
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min) + min;
    }
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        cout << "Введен неправильный диапазон" << endl;
        abort();
    }
}

void replaceLastKWithOpposite(int* arr, const int n, const size_t k) {
    // Определяем количество элементов для замены
    size_t elementsToReplace = (k > static_cast<size_t>(n)) ? static_cast<size_t>(n) : k;  // Исправлен тип

    for (size_t i = 0; i < elementsToReplace; ++i) {  // Исправлен тип переменной
        arr[n - 1 - i] = -arr[n - 1 - i]; // Заменяем элемент на противоположный
    }
}

int sumNegativeElements(const int* arr, const int n) {
    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void printIndicesOfMultiplesOfThree(const int* arr, const int n) {
    cout << "Индексы элементов, кратных 3: ";
    bool found = false; // Флаг для проверки наличия кратных 3 элементов
    for (size_t i = 0; i < n; i++) {
        if (arr[i] % 3 == 0) {
            cout << i << " "; // Выводим индекс элемента
            found = true;
        }
    }
    if (!found) {
        cout << "Нет элементов, кратных 3.";
    }
    cout << endl;
}

int findPairWithSum(const int* arr, const int n, const int target) {  // Добавлен const
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i] + arr[i + 1] == target) {
            return i; // Возвращаем индекс первого элемента пары
        }
    }
    return -1; // Если пара не найдена
}

void fillArray(int* arr, const int n, const int min, const int max)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter value for arr[" << i << "]: ";
        arr[i] = getNumber();
        if (arr[i] < min || arr[i] > max)
        {
            cout << "Значение вне диапазона" << endl;
            i--;
        }
    }
}