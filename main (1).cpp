#include <iostream>
using namespace std;

/**
*@brief Переводит вес из граммов в унции
*@return возвращает значение в унциях
*/
double gramms_in_ounces(double gramms, double const ounces) {
    return gramms / ounces;
}
/**
*@brief Запрашивает ввод данных с клавиатуры
*@return возвращает значение в граммах
*/
double testinput() {
    double gramms;
    cout << "Введите вес в граммах: ";
    cin >> gramms;
    return gramms;
}

int main() {
    setlocale(LC_ALL, "ru");
    const double ounces = 28.3;
    
    double gramms = testinput();
    if (gramms < 0) {
        cout << "Ошибка: вес не может быть отрицательным!" << endl;
        return 1;
    }
    
    cout << "Ввод выполнен корректно!" << endl;
    cout << "Вес в унциях: " << gramms_in_ounces(gramms, ounces);
    
    return 0;
}