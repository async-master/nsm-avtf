#include <iostream>
#include <string>

int main()
{
    std::string str = "##Hel##lo worl##d##";
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
    
    return 0;
}
