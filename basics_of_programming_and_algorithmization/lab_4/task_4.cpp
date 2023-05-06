#include <iostream>
#include <fstream>
#include <string>

int word_count(std::string file_name){
    std::ifstream file;
    file.open(file_name);
    
    if(file.is_open()){
        int count = 1;
        std::string str;
        getline(file,str);
        
        for (int i = 0; i < str.size(); i++)
            if (str[i] == ' ') count++;
            
        file.close();
        return count;
    }
    else{
        file.close();
    }
    return 0;
}

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
    std::string file_name; std::cout << "Input file name: "; std::cin >> file_name;
    int words = word_count(file_name);
    
    std::string arr[words];
    
    std::ifstream file;
    file.open(file_name);
    
    if(file.is_open()){
    
        for(int i=0; i<=words;i++){
            file >> arr[i];
        }
    
        insertion_sort_vowel(arr, words);

        for(int i=words; i>=0;i--){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "World with count('a') >=2: " << std::endl;
        for(int i=words; i>=0;i--){
            if(a_count(arr[i])>=2) std::cout<<arr[i]<<" ";
        }
    }else{
        std::cout << "ERROR";
    }
    
    return 0;
}
