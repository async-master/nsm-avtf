#include <iostream>
#include <string>

void insertion_sort_len_word(std::string *arr, int size){
	for(int i=0;i<size;i++){
		std::string x=arr[i];
		int j=i-1;
		while(j>=0 && arr[j].length()>=x.length()){
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
    
    insertion_sort_len_word(arr, word_count);

    for(int i=word_count; i>=0;i--){
        std::cout << arr[i] << " ";
    }
    
    return 0;
}
