#include <iostream>

void selection_sort(float *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index]) min_index = j;
        }
        if (min_index != i)
        {
			float temp = arr[i];
            arr[i] = arr[min_index];	
			arr[min_index] = temp;
        }
    }
}

int main(){
	int size; std::cout << "Введите размер массива: "; std::cin >> size;
	float *randomDigits = new float[size];
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
	selection_sort(randomDigits,size);
	std::cout <<"Отсортированный массив: " << std::endl;
	for(int i = 0; i < size; i++) std::cout << randomDigits[i] << " ";
	std::cout << std::endl;
}
