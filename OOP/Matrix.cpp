#include "Matrix.h"
#include<iostream>
#include<vector>

void Matrix::printSize() {
    std::cout << "rows: " << this->rows << "; " << "colms: " << this->colms << "; \n";
}

void Matrix::fullIn() {
    m.resize(rows);
    for (int i = 0; i < rows; i++) {
        m[i].resize(colms);
        for (int j = 0; j < colms; j++) {
            m[i][j] = rand() % 10;
        }
    }
}

void Matrix::printSize() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colms; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Matrix::miltOnNum(int num) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colms; j++) {
            m[i][j] *= num;
        }
    }
}

void Matrix::resize(int rows, int colms) {
    m.resize(rows);
    for (int i = 0; i < rows; i++) {
        m[i].resize(colms);
    }
}

Matrix Matrix::transp() {
    Matrix temp(colms, rows);
    temp.resize(colms, rows);

    for (int i = 0; i < colms; i++) {
        temp[i].resize(rows);
        for (int j = 0; j < rows; j++) {
            temp[i][j] = m[j][i];
        }
    }
    return temp;
}