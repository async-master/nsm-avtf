#include <iostream>

int main()
{
	std::cout<<"Введите кол-во столбцов матрицы: "; int m; std::cin>>m;
	std::cout<<"Введите кол-во строк матрицы:    "; int n; std::cin>>n;
	int** matrix = new int*[m];
	for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			matrix[i][j]=rand()%100;
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


	for(int j=0;j<n;j++){
		int max,iMax,min,iMin=0;
		for(int i=0;i<m;i++){
			iMax=(matrix[i][j]>max)?i:iMax;
			max=matrix[iMax][j];
			iMin=(matrix[i][j]<min)?i:iMin;
			min=matrix[iMin][j];
		}
		int temp=matrix[iMin][j];
		matrix[iMin][j]=matrix[iMax][j];
		matrix[iMax][j]=temp;
	}


	std::cout<<"Отредактированная матрица: " << std::endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}


	for (int i = 0; i < m; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}
