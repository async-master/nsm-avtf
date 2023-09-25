#include <iostream>
#include <Matrix.h>

int main()
{
    std::cout << "Hello World!\n";
    int rows, colms,num;
    do {
        std::cin >> rows >> colms >> num;
        Matrix a(rows, colms);
        a.print_size();
        a.full_in();
        a.print_matrix();
        if (num != 1) {
            a.milt_on_num(num);
            std::cout << "\n";
            a.print_matrix();
        }

        
    } while (rows != 0);
}
