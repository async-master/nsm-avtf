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
        const int len = str.length();
        int n = 0;
        
        for (int i = 0; i < len; i++) {
            if (str.at(i) == 'a') n++;
        }

        for(int i = 0; i < len+n; i++) {
            if (str.at(i) == 'a') {
                std::string str1(str, 0, i+1);
                std::string str2(str, i+1, len+1);
                str.clear();
                str.append(str1).append("b").append(str2);
            }
        }
        
        std::cout << str;
    }
    file.close();

    return 0;
}
