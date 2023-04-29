#include <iostream>
#include <string>

int vowel_count(std::string str){
    int n=0;
    for(int i=0; i<=str.length();i++){
        if(int(str[i])==97||int(str[i])==101||int(str[i])==105||int(str[i])==111||int(str[i])==117||int(str[i])==121) n++;
    }
    return n;
}

int a_count(std::string str){
    int n=0;
    for(int i=0; i<=str.length();i++){
        if(int(str[i])==97) n++;
    }
    return n;
}

void insertion_sort_vowel(std::string *arr, int size){
	for(int i=0;i<size;i++){
		std::string x=arr[i];
		int j=i-1;
		while(j>=0 && vowel_count(arr[j])>=vowel_count(x) && int(arr[j][0])<=int(x[0])){
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
    
    insertion_sort_vowel(arr, word_count);

    for(int i=word_count; i>=0;i--){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Все слова с двумя и более буквами 'a': " << std::endl;
    for(int i=word_count; i>=0;i--){
        if(a_count(arr[i])>=2) std::cout<<arr[i]<<" ";
    }
    
    return 0;
}
