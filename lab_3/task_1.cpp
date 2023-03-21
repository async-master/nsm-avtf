#include <iostream>

int main()
{
	std::cout<<"Введите размер матрицы: " << std::endl;
	std::cout<<"Введите кол-во столбцов: "; int m; std::cin>>m;
	std::cout<<"Введите кол-во строк:    "; int n; std::cin>>n;
	
	int** matrix = new int*[m];

	for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }


	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			matrix[i][j] = rand()%10;
		}
	}
	std::cout<<"Исходная матрица: " << std::endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout<<"Нечётные столбцы матрицы: " << std::endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j+=2){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	for (int i = 0; i < m; i++) // To delete the inner
                                // arrays
        delete[] matrix[i];
    delete[] matrix;
	
	return 0;
}

