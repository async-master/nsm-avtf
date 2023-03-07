#include <iostream>
#include <cmath>
using namespace std;

float triangels(int n,int a){
    if(a==0)return 0;
	float sum = 0;
	for(int i=0; i<n;i++){
		sum+=pow(a*pow(i+1,0.5)+i,2)*0.25*pow(3,0.5);
	} 
	return 	sum/n;
	
}

int main(){
	double n; double a; 
	
	cout << "Введите количество треугольников (натуральное число): ";
	cin >> n; 
	if(!(n>0 && n==round(n))){
	    cout << "Вы ввели ненатуральое число...";
	    return 0;
	}
	
	cout << "Введите длину стороны (число >= 0): ";
	cin >> a; 
	if(!(a>=0)){
	    cout << "Введенная длина не >= 0";
	    return 0;
	}
	
	cout << triangels(n,a);
	
	return 0;
}
