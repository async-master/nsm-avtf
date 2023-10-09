#include "Matrix.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
/*
std::vector<std::vector<double>> Matrix::getCofactor(std::vector<std::vector<double>> vect, int size) {
    if (vect.size() != vect[0].size()) {
        throw std::runtime_error("Matrix is not quadratic");
    }

    std::vector<std::vector<double>> solution(vect.size(), std::vector<double>(vect.size()));
    std::vector<std::vector<double>> subVect(vect.size() - 1, std::vector<double>(vect.size() - 1));

    for (std::size_t i = 0; i < vect.size(); i++) {
        for (std::size_t j = 0; j < vect[0].size(); j++) {

            int p = 0;
            for (size_t x = 0; x < vect.size(); x++) {
                if (x == i) {
                    continue;
                }
                int q = 0;

                for (size_t y = 0; y < vect.size(); y++) {
                    if (y == j) {
                        continue;
                    }

                    subVect[p][q] = vect[x][y];
                    q++;
                }
                p++;
            }
            solution[i][j] = pow(-1, i + j) * det(subVect, size);
        }
    }
    return solution;
}
*/

Matrix::Matrix( std::string str) {
    this->colms = 0;
    this->rows = 0;

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
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->colms; j++) {
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

double Matrix::det(std::vector<std::vector<double>> m, int n) {
    double num1, num2, det = 1, index, total = 1;
    double* temp{ new double[n + 1] };
    for (int i = 0; i < n; i++)
    {
        index = i;
        while (index < n && m[index][i] == 0)  index++;
        if (index == n)continue;
        if (index != i) {
            for (int j = 0; j < n; j++) {
                double temp = m[index][j];
                m[index][j] = m[i][j];
                m[i][j] = temp;
            }
            det = det * pow(-1, index - i);
        }
        for (int j = 0; j < n; j++) {
            temp[j] = m[i][j];
        }
        for (int j = i + 1; j < n; j++) {
            num1 = temp[i];
            num2 = m[j][i];
            for (int k = 0; k < n; k++) {
                m[j][k]
                    = (num1 * m[j][k]) - (num2 * temp[k]);
            }
            total = total * num1;
        }
    }
    delete[] temp;
    for (int i = 0; i < n; i++) {
        det = det * m[i][i];
    }
    return (det / total);
}
/*
std::vector<std::vector<double>> Matrix::getInverse(const std::vector<std::vector<double>> vect, int size) {
    if (det(vect,size) == 0) {
        throw std::runtime_error("Determinant is 0");
    }

    double d = 1.0 / det(vect,size);
    std::vector<std::vector<double>> solution(vect.size(), std::vector<double>(vect.size()));

    for (size_t i = 0; i < vect.size(); i++) {
        for (size_t j = 0; j < vect.size(); j++) {
            solution[i][j] = vect[i][j];
        }
    }
    Matrix temp(colms, rows);
    temp.m.resize(temp.rows);
    for (int i = 0; i < temp.rows; i++) {
        temp.m[i].resize(temp.colms);
        for (int j = 0; j < temp.colms; j++) {
            temp.m[i][j] = vect[j][i];
        }
    }
    temp.getCofactor(solution, size);
    temp.transp();
    solution = temp.rtnM();

    for (size_t i = 0; i < vect.size(); i++) {
        for (size_t j = 0; j < vect.size(); j++) {
            solution[i][j] *= d;
        }
    }

    return solution;
}
*/
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

void Matrix::outInCSVFile() {
    std::string str; std::cout << "Введите название файла записи: "; std::cin >> str;
    std::ofstream out(str);

    if (out.is_open())
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colms; j++) {
                out << m[i][j] << ",";
            }
            out << "\n";
        }
    }
    out.close();
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        m[i].resize(colms);
        for (int j = 0; j < colms; j++) {
            m[i].clear();
        }
    }
    m.clear();
}
