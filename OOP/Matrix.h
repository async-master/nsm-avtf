#pragma once
#include<vector>

class Matrix {
    int rows;
    int colms;
    std::vector<std::vector<double>> m;
    void resize(int rows, int colms);
public:
    Matrix();
    Matrix(int rows, int colms) : rows(rows), colms(colms);
    void printSize();
    void fullIn();
    void printMatrix();
    void miltOnNum(int num);
    void resize(int rows, int colms);
    Matrix transp();
    ~Matrix();
};