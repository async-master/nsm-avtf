#include <iostream>
#include <cstdlib>

void insertion_sort(float *arr, int size){
	for(int i=0;i<=size;i++){
		float x=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>x){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=x;
	}
}

int main(){
	int size; std::cout << "Введите размер массива: "; std::cin >> size;
	float randomDigits[size] {};
	for(int i = 0; i < size; i++) randomDigits[i] = 0.01 * (rand() % 101);
	for(int i = 0; i < size; i++) std::cout << randomDigits[i] << " ";
	std::cout << std::endl;
	insertion_sort(randomDigits,size);
	for(int i = 0; i < size; i++) std::cout << randomDigits[i] << " ";
	std::cout << std::endl;
	
}
