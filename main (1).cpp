#include <iostream> 
using namespace std;

double gramms_in_onces(double gramms, double const oncies) {
 return gramms / oncies;
}

double testinput() {
 double gramms;
 do {
  cout << "Введите вес в граммах : ";
  cin >> gramms;
  if (gramms < 0) cout << "Данные введены некорректно! Попробуйте снова (граммы >= 0). " << endl;
  else cout << "Ввод выполнен кореектно! " << endl;
 } while (gramms < 0);
 return gramms;
}

int main() {
 setlocale (LC_ALL, "ru");
 const double ounces = 28.3;
 double gramms;  
 gramms = testinput();
 cout << "Перевод из грамм в унции. " << endl;
 cout << "Вес в унциях: " << gramms_in_onces(gramms, ounces);
}