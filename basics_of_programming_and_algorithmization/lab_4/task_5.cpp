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
    std::string file_name; std::cout << "Input file name: "; std::cin >> file_name;
    int words = word_count(file_name);
    
    std::string arr[words];
    
    std::ifstream file;
    file.open(file_name);
    
    if(file.is_open()){
    
        for(int i=0; i<words;i++){
            file >> arr[i];
        }
    
        insertion_sort_len_word(arr, words);

        for(int i=words; i>=0;i--){
        std::cout << arr[i] << " ";
        }
    
        return 0;
    }else{
        file.close();
    }
    return 0;
}
