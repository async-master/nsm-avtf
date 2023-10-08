#include <iostream>
#include <vector>
#include <string> 
#include <Matrix.h>
int main()
{
    
    int n;
    Matrix a{};
    Matrix q{};
    std::string fName;
    setlocale(LC_ALL, "Russian");
    do {
        std::cout << "Что бы создать матрицу нажмите 1 \n";
        std::cout << "Что бы умножить матрицу на число нажмите 2 \n";
        std::cout << "Что бы транспонировать матрицу нажмите 3 \n";
        std::cout << "Что бы найти определитель матрицы нажмите 4 \n";
        std::cout << "Что бы вывести матрицу нажмите 5 \n";
        std::cout << "Что бы вывести матрицу в файл нажмите 6 \n";
        std::cout << "Что бы удалить матрицу нажмите 7 \n";
        std::cin >> n;
        switch (n) {
        case 1:
            {
            std::cout << "Введите название файла, содержащего матрицу: ";
            std::cin >> fName;
            
                Matrix b{ fName };
                a = b;
            };
            break;
        case 2:
            std::cout << "Введите число на которое хотите умножить матрицу: \n";
            double num; std::cin >> num;
            a.miltOnNum(num);
        case 3:
            a = a.transp();
            break;
        case 4:
            if (a.rtnColms() != a.rtnRows()) {
                std::cout << "Требуется Квадратная матрица. \n \n";
                continue; 
            }
            std::cout << a.det(a.rtnM(), a.rtnColms()) << "\n";
            break;
        case 5:
            if (a.rtnColms() == 0) {
                std::cout << "Сначала создайте матрицу. \n";
            }
            if (a.rtnColms() != 0) {
                std::cout << "\n";
                a.printMatrix();
            }
            break;
        case 6:
            a.outInTextFile();
            break;
        case 7:
            a = q;
            break;
        default:
            continue;
            break;
        }
    } while (n != 0);
    std::cout << "Программма завершена успешно. \n";
}
