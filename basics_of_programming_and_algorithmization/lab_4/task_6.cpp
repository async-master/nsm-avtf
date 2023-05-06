#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string file_name; std::cout << "Input file name: "; std::cin >> file_name;
    
    std::ifstream file;
    file.open(file_name);
    
    if(file.is_open()){
    
        std::string str;
        getline(file,str);
        const int length = str.length();

        int n = 0;
        for (int i = 0; i < length; i++) {
            if (str.at(i) == '#') n++;
        }
        bool ch = false;
        for(int i = 0; i < length-n/2; i++) {
            if (str.at(i) == '#' && str.at(i+1) == '#') {
                if(!ch){
                    std::string str1(str, 0, i);
                    std::string str2(str, i+2, length+1);
                    str.clear();
                    str.append(str1).append("<").append(str2);
                    ch = true;
                    continue;
                }
                if(ch){
                    std::string str1(str, 0, i);
                    std::string str2(str, i+2, length+1);
                    str.clear();
                    str.append(str1).append(">").append(str2);
                    ch = false;
                    continue;
                }
            }
        }
       
        std::cout << str;
    }else{
        std::cout<<"ERROR"<<std::endl;
    }
    return 0;
}
