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
