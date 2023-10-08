#include <iostream>
#include <vector>
#include <string> 
#include <fstream>

class Matrix {
    int rows;
    int colms;
    std::vector<std::vector<double>> m;
public:
    Matrix() : rows(0), colms(0),m{0}
    {}
    Matrix(int rows, int colms) : rows(rows), colms(colms), m{}
    {}
    Matrix(std::string str);

    int rtnRows() { return rows; }
    int rtnColms() { return colms; }
    std::vector<std::vector<double>> rtnM() { return m; }

    void printMatrix();
    void miltOnNum(double num);
    Matrix transp();
    double det(std::vector<std::vector<double>> m, int rows);
    void outInTextFile();
    ~Matrix();
};

Matrix::Matrix(std::string str) {
    std::ifstream in(str); // окрываем файл для чтения
    if (in.is_open()) {
        in >> rows >> colms;
        m.resize(rows);
        for (int i = 0; i < rows; i++) {
            m[i].resize(colms);
            for (int j = 0; j < colms; j++) {
                in >> m[i][j];
            }
        }
    }
    else {
        std::cout << "Попробуйте ещё раз. \n";
    }
    in.close();
}

void Matrix::printMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colms; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Matrix::miltOnNum(double num) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colms; j++) {
            m[i][j] *= num;
        }
    }
}

Matrix Matrix::transp() {
    Matrix temp(colms, rows);
    temp.m.resize(temp.rows);
    for (int i = 0; i < temp.rows; i++) {
        temp.m[i].resize(temp.colms);
        for (int j = 0; j < temp.colms; j++) {
            temp.m[i][j] = m[j][i];
        }
    }
    return temp;
}

double Matrix::det(std::vector<std::vector<double>> m,int n) {
    double num1, num2, det = 1, index, total = 1;
    int* temp{ new int[n+1] };
    for (int i = 0; i < n; i++)
    {
        index = i;
        while (index < n && m[index][i] == 0)  index++;
        if (index == n)continue;
        if (index != i){
            for (int j = 0; j < n; j++){
                int temp = m[index][j];
                m[index][j] = m[i][j];
                m[i][j] = temp;
            }
            det = det * pow(-1, index - i);
        }
        for (int j = 0; j < n; j++){
            temp[j] = m[i][j];
        }
        for (int j = i + 1; j < n; j++){
            num1 = temp[i];
            num2 = m[j][i];
            for (int k = 0; k < n; k++){
                m[j][k]
                    = (num1 * m[j][k]) - (num2 * temp[k]);
            }
            total = total * num1;
        }
    }
    delete temp;
    for (int i = 0; i < n; i++){
        det = det * m[i][i];
    }
    return (det / total);
}

void Matrix::outInTextFile() {
    std::string str; std::cout << "Введите название файла записи: "; std::cin >> str;
    std::ofstream out(str);

    if (out.is_open())
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colms; j++) {
                out << m[i][j] << " ";
            }
            out << "\n";
        }
    }
    out.close();
}
/*void Matrix::outInXLSFile() {
    std::string str; std::cout << "Введите название файла записи: "; std::cin >> str;
    std::ofstream out;

    if (out.is_open())
    {
        out.open("str", ios::app);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colms; j++) {
                out << m[i][j] << " ";
            }
            out << "\n";
        }
    }
    out.close();
}*/

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        m[i].resize(colms);
        for (int j = 0; j < colms; j++) {
            m[i].clear();
        }
    }
    m.clear();
}

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
