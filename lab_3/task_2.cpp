#include <iostream>

int main()
{
	std::cout<<"Введите порядок матрицы: "; int n; std::cin>>n;
	
	int** matrix = new int*[n];

	for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }


	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matrix[i][j] = rand()%10;
		}
	}
	std::cout<<"Исходная матрица: " << std::endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout<<"Обнуление элементов матрицы выше побочной диагонали матрицы: " << std::endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			std::cout << matrix[i][j] * ((i+j)/(n-1)) << " ";
		}
		std::cout << std::endl;
	}
	
	for (int i = 0; i < n; i++) // To delete the inner
                                // arrays
        delete[] matrix[i];
    delete[] matrix;
	
	return 0;
}
