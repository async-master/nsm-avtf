#include <iostream>
#include <string>
#include <iterator>

bool check_symbol(char symbol, std::string str);

int main()
{
    std::string str1 = "abbcccddd";
    std::string str2 = "aaaabbbccd";

    const int len1 = str1.length();
    const int len2 = str2.length();

    std::string str3 = ""; // конечная строка.
    std::string str4 = ""; // символы которые уже были.

    for(int i=0;i<len1;i++){
        if(check_symbol(str1.at(i), str1)){//проверяем не был ли уже символ
            str4.append(str1.at(i));
            int n = 0; // счётчик вхождения символа в строку 1.
            for(int j=0;j<str1.length();j++){
                if(str1.at(i) == str1.at(j)) n++;
            }
            int m = 0; // счётчик вхождения символа в строку 2.
            for(int j=0;j<str2.length();j++){
                if(str2.at(j) == str1.at(i)) m++;
            }
            int p = (n>m)? m:n;
            for(int j=1;j<=p;j++) str3.append(str1.at(i))
        }else{
            
        }
    }

    std::cout << str3;

    return 0;
}

bool check_symbol(char symbol, std::string str){
    for(int i=0;i<str4.length();i++){
        if(str4.at(i) == symbol) return false;
    }
    return true;
}
