#include <iostream>
#include <string>

int vowel_count(std::string str){
    int n=0; //counting vowel
    for(int i=0; i<=str.length();i++){
        if(int(str[i])==97||int(str[i])==165||int(str[i])==168||int(str[i])==174||int(str[i])==227||int(str[i])==235||int(str[i])==237||int(str[i])==238||int(str[i])==239||int(str[i])==241) n++;
    }
    return n;
}

void insertion_sort(std::string *arr, int size){
	for(int i=0;i<size;i++){
		std::string x=arr[i];
		int j=i-1;
		while(j>=0 && vowel_count(arr[j])>=vowel_count(x)){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=x;
	}
}

int main()
{
    int word_count; std::cout << "Введите кол-во слов, которое вы хотите ввести: "; std::cin >> word_count;
    
    std::string arr[word_count];
    
    for(int i=0; i<word_count;i++){
        std::cin >> arr[i];
    }
    
    insertion_sort(arr, word_count);

    for(int i=0; i<word_count;i++){
        std::cout << arr[i] << " ";
    }
    
    return 0;
}
