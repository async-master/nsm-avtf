#include <iostream>

void insertion_sort(float *arr, int size){
	for(int i=0;i<size;i++){
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
	float *randomDigits = new float[size];
	for(int i = 0; i < size; i++){
	    if(i%2 == 1){
	        randomDigits[i] = -0.01 * (rand() % 1001);
	        continue;
	    }
	    randomDigits[i] = 0.01 * (rand() % 1001);
	}
	std::cout <<"Не отсортированный массив: " << std::endl;
	for(int i = 0; i < size; i++) std::cout << randomDigits[i] << " ";
	std::cout << std::endl;
	insertion_sort(randomDigits,size);
	std::cout <<"Отсортированный массив: " << std::endl;
	for(int i = 0; i < size; i++) std::cout << randomDigits[i] << " ";
	std::cout << std::endl;
}
