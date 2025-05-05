#include <iostream>
using namespace std;

/**
*@brief Переводит вес из граммов в унции
*@return возвращает значение в унциях
*/
double gramms_in_ounces(double gramms);

/**
*@brief Запрашивает ввод данных с клавиатуры
*@return возвращает значение в граммах
*/
double testinput();

int main() 
{
    setlocale(LC_ALL, "ru");
       
    double gramms = testinput();
    if (gramms < 0) {
        cout << "Ошибка: вес не может быть отрицательным!" << endl;
        return 1;
}
    
    cout << "Ввод выполнен корректно!" << endl;
    cout << "Вес в унциях: " << gramms_in_ounces(gramms, ounces);
    
    return 0;
}

double gramms_in_ounces(double gramms) {
    const double ounces = 28.3;
    return gramms / ounces;
}

ouble testinput() {
    double gramms = 0;
    cout << "Введите вес в граммах: ";
    cin >> gramms;
    if (cin.fail())
    {
        cout<<"Error value"<<endl;
        abort();
    }
    return gramms;
}

