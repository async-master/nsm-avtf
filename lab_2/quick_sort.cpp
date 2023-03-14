#include <iostream>
using namespace std;
  
int partition(float *arr, int low, int high){
    float pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    float temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quickSort(float *arr, int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{   
    int size; std::cout << "Введите размер массива: "; std::cin >> size;
	float randomDigits[size] {};
	for(int i = 0; i < size; i++){
	    if(i%2 == 1){
	        randomDigits[i] = -0.01 * (rand() % 101);
	        continue;
	    }
	    randomDigits[i] = 0.01 * (rand() % 101);
	}
	std::cout <<"Не отсортированный массив: " << std::endl;
	for(int i = 0; i < size; i++) std::cout << randomDigits[i] << " ";
	std::cout << std::endl;
	quickSort(randomDigits,0,size-1);
	std::cout <<"Отсортированный массив: " << std::endl;
	for(int i = 0; i < size; i++) std::cout << randomDigits[i] << " ";
	std::cout << std::endl;
	
    return 0;
}
