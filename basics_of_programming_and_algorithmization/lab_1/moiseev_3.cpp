#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

double speed(double a, double m, double t) {
	if (a == 0 || t == 0) return 0;
    float g = 9.81;
    return t * g * (sin(a*3.14/180) - m * cos(a * 3.14 / 180));
}
int main() {
    setlocale(LC_ALL, "RUSSIAN");
    system("color F0");
    double a, m, t;
    cout << "Введите значение угла из отрезка [-90;90]: "; cin >> a; a = abs(a);
    if (!(a >= 0 && a <= 90)) {
		cout << "Значение угла не в заданном отрезке.";
		return 0;
    }
    cout << "Введите значение коэффициента трения из диапозона [0;1]: "; cin >> m;
    if (!(m >= 0 && m <= 1)) {
		cout << "Значение коэффициента трения не из диапозона [0;1]";
		return 0;
    }
    cout << "Введите время (t>=0): "; cin >> t;
    if (!(t >= 0)) {
		cout << "Время не из диапозона t>=0";
		return 0;
    }
    cout << speed(a, m, t);
    return 0;
}
