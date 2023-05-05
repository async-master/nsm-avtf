#include <iostream>
#include <iterator>
#include <string>
int main()
{
    std::string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    const int length{ static_cast<int>(std::size(str)) };

    int n = 0;
    for (int i = 0; i < length; i++) {
        if (str.at(i) == 'a') n++;
    }

    for(int i = 0; i < length+n; i++) {
        if (str.at(i) == 'a') {
            std::string str1(str, 0, i+1);
            std::string str2(str, i+1, length+1);
            str.clear();
            str.append(str1).append("b").append(str2);
            
            
        }
    }
       
    std::cout << str;


    return 0;
}
