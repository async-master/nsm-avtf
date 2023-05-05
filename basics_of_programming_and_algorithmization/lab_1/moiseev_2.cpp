#include <iostream>
using namespace std;


static int size = 5;


int move_arr(int* arr){
    
    int k; cout << "Введите число >= 0: "; cin >> k;
    if(!(k>=0)){
	    cout << "Смотреть условие ввода! ";
	    return 0;
	}
	
	for(int i=size;i>=0;i--){
	    if(i<k){
	        arr[i]=0;
	        continue;
	    }
	    arr[i] = arr[i-k];
	    
	}
	
	for(int i=0; i<size;i++) cout << *(arr + i) << " ";
	return 0;
}

int main(){
    
	int arr[size] = {1,2,3,4,5};
    
	move_arr(arr);

	return 0;
}
