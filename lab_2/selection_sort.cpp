#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

void swap(float *xp, float *yp) {
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(float arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        if (min_idx != i) swap(arr[min_idx], arr[i]);
    }
}
void printArray(float arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int size; std::cout << "Введите размер массива: "; std::cin >> size;
    float randomDigits[size] {};
	for(int i = 0; i < size; i++) randomDigits[i] = 0.01 * (rand() % 1001);
	for(int i = 0; i < size; i++) std::cout << randomDigits[i] << " ";
    selectionSort(randomDigits, size);
    cout << "Sorted array: \n";
    printArray(randomDigits,size);
    return 0;
}