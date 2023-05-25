#include <iostream>
#include <fstream>

int main()
{
    std::string file_name; std::cout << "Input file name: "; std::cin >> file_name;
    
    std::ifstream file;
    file.open(file_name);
    
    if(file.is_open()){
        
        std::string str;
        getline(file,str);
        const int len=str.length();
        char arr[len];
        for(int i=0;i<len;i++){
            arr[i]=str[i];
        }
        int n = 0;
        for (int i = 0; i <= len; i++) {
            if (arr[i] == 'a') arr[i] = 'A';
            if (arr[i] == 'b') arr[i] = 'B';
        }
        std::cout << arr;
    }else{
        std::cout << "ERROR"<<std::endl;
    }
    return 0;
}
