#include <iostream>
#include <cstdlib>

float quick_sort(float *arr, float low, float high){
	return quick_sort
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
