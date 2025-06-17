#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

/**
 * @brief считывает целое число с клавиатуры с проверкой ввода
 * @return считанное значение
 */
int getValue();

/**
 * @brief считывает размер матрицы (целое число) с клавиатуры с проверкой, что оно положительное
 * @return считанное значение, преобразованное в size_t
 */
size_t getSize();

/**
 * @brief проверяет, что введенное значение удовлетворяет условию n>0
 * @param n проверяемое значение
 */
void checkN(const int n);

/**
 * @brief выделяет память под двумерный массив размером m x n
 * @param m количество строк
 * @param n количество столбцов
 * @return указатель на созданный массив
 */
int** getNewArray(const size_t m, const size_t n);

/**
 * @brief выводит двумерный массив на экран
 * @param array массив для вывода
 * @param m количество строк
 * @param n количество столбцов
 */
void printArray(int** array, const size_t m, const size_t n);

/**
 * @brief заполняет массив значениями, вводимыми пользователем с клавиатуры
 * @param array массив для заполнения
 * @param m количество строк
 * @param n количество столбцов
 */
void fillArray(int** array, const size_t m, const size_t n);

/**
 * @brief меняет знак максимального элемента в каждой строке на противоположный
 * @param array массив
 * @param m количество строк
 * @param n количество столбцов
 */
void changeMaxElementInLine(int** array, const size_t m, const size_t n);

/**
 * @brief находит индекс максимального элемента в одномерном массиве (строке)
 * @param array одномерный массив (строка)
 * @param n количество элементов в массиве
 * @return индекс максимального элемента
 */
size_t getMaxIndexInLine(int* array, const size_t n);

/**
 * @brief создает копию двумерного массива
 * @param array исходный массив
 * @param m количество строк
 * @param n количество столбцов
 * @return указатель на копию массива
 */
int** copyArray(int** array, const size_t m, const size_t n);

/**
 * @brief освобождает память, занятую двумерным массивом
 * @param array массив
 * @param m количество строк
 * @param n количество столбцов
 */
void deleteArray(int** array, const size_t m, const size_t n);

/**
 * @brief находит максимальный элемент во всем массиве
 * @param array массив
 * @param m количество строк
 * @param n количество столбцов
 * @return максимальный элемент массива
 */
int findMaxElement(int** array, const size_t m, const size_t n);

/**
 * @brief подсчитывает количество столбцов, содержащих максимальный элемент массива
 * @param array массив
 * @param m количество строк
 * @param n количество столбцов
 * @return количество столбцов с максимальным элементом
 */
int getCountOfMaxElementColumns(int** array, const size_t m, const size_t n);

/**
 * @brief создает новый массив с добавлением столбцов нулей после столбцов с максимальным элементом
 * @param array исходный массив
 * @param m количество строк
 * @param n количество столбцов в исходном массиве
 * @param newarray новый массив (должен быть заранее выделен под размер m x (n + k), где k - количество столбцов с максимальным элементом)
 */
void addNewColumns(int** array, const size_t m, const size_t n, int** newarray);

/**
 * @brief заполняет массив случайными числами в заданном диапазоне
 * @param array массив
 * @param m количество строк
 * @param n количество столбцов
 * @param start начало диапазона
 * @param end конец диапазона
 */
void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end);

/**
 * @brief перечисление для выбора способа заполнения массива
 * 
 * RANDOM = 5 - заполнение случайными числами
 * MANUAL = 6 - ручной ввод элементов
 */
enum {RANDOM = 5, MANUAL =6};

/**
 * @brief точка входа в программу
 * @return 0
 */
int main()
{
    cout<< "Enter m: ";
    size_t m = getSize();
    cout<< "Enter n: ";
    size_t n = getSize();
    int** array = getNewArray(m,n);
    cout<< "Enter the way to fill array: "<< (int)MANUAL<<
        " to fill manually, "<< (int)RANDOM<< " to fill randomly: ";
    int choice = getValue();
    int start = 0;
    int end = 0;
    switch (choice)
    {    
        case RANDOM:    cout<< "Enter start: ";
                        start = getValue();
                        cout<< "Enter end: ";
                        end = getValue();
                        fillRandom(array, m, n, start, end);
                        break;
        case MANUAL:    fillArray(array,m,n);
                        break;
        default:
                        cout<<"Error"<<endl;
                        return 1;
                        break;
    }
    cout << "\nOriginal array:" << endl;
    printArray(array, m, n);
  
    int** arrayCopy = copyArray(array, m, n);
    changeMaxElementInLine(arrayCopy, m, n);
    cout << "\nAfter changing max elements in each row:" << endl;
    printArray(arrayCopy, m, n);
    deleteArray(arrayCopy, m, n);

    size_t newn = n + getCountOfMaxElementColumns(array, m, n);
    int** resultarray = getNewArray(m, newn);
    addNewColumns(array, m, n, resultarray);
    cout << "\nAfter inserting zero columns after columns with max element:" << endl;
    printArray(resultarray, m, newn);
    
    deleteArray(resultarray, m, newn);
    deleteArray(array, m, n);
    
    return 0;
}

void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end)
{
    srand(time(0));
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            array[i][j] = rand() % (end - start +1 ) + start;
        }
    }
}

int getValue()
{
    int value = 0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Error"<<endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    int n = getValue();
    checkN(n);
    return (size_t)n;
}

void checkN(const int n)
{
    if (n<=0)
    {
        cout<<"Error"<<endl;
        abort();
    }
}

int** getNewArray(const size_t m, const size_t n)
{
    int** array = new int*[m];
    for (size_t i = 0; i<m; i++)
    {
        array[i] = new int[n];
    }
    return array;
}

void printArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            cout<<setw(6)<<array[i][j];
        }
        cout<<endl;
    }
}

void fillArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            cout<<"Enter array["<<i<<","<<j<<"] = ";
            array[i][j] = getValue();
        }
    }
}

size_t getMaxIndexInLine(int* array, const size_t n)
{
    size_t  maxIndex =0; 
    for (size_t i=0; i<n; i++)
    {
        if (array[i] > array[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void changeMaxElementInLine(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        int maxInRow = array[i][0];
        for (size_t j = 1; j < n; j++)
        {
            if (array[i][j] > maxInRow)
            {
                maxInRow = array[i][j];
            }
        }
        for (size_t j = 0; j < n; j++)
        {
            if (array[i][j] == maxInRow)
            {
                array[i][j] = -array[i][j];
            }
        }
    }
}
int** copyArray(int** array, const size_t m, const size_t n)
{
    int** result = getNewArray(m,n);
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            result[i][j] = array[i][j];
        }
    }
    return result;
}

void deleteArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i<m; i++)
    {
        delete [] array[i];
    }
    delete [] array;
}

int findMaxElement(int** array, const size_t m, const size_t n)
{
    int maxElement = array[0][0];
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            if (array[i][j] > maxElement)
            {
                maxElement = array[i][j];
            }
        }
    }
    return maxElement;
}

int getCountOfMaxElementColumns(int** array, const size_t m, const size_t n)
{
    int maxElement = findMaxElement(array, m, n);
    int count = 0;
    for (size_t j = 0; j<n; j++)
    {
        for (size_t i = 0; i<m; i++)
        {
            if (array[i][j] == maxElement)
            {
                count++;
                break;
            }
        }
    }
    return count;
}

void addNewColumns(int** array, const size_t m, const size_t n, int** newarray)
{
    int maxElement = findMaxElement(array, m, n);
    size_t newj = 0;
    for (size_t j = 0; j<n; j++)
    {
        for (size_t i = 0; i<m; i++ )
        {
            newarray[i][newj] = array[i][j];
        }
        newj++;

        bool hasMax = false;
        for (size_t i = 0; i<m; i++)
        {
            if (array[i][j] == maxElement)
            {
                hasMax = true;
                break;
            }
        }
    
        if (hasMax)
        {
            for (size_t i = 0; i<m; i++)
            {
                newarray[i][newj] = 0;
            }
            newj++;
        }
    }
}