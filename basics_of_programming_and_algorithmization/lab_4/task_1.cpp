#include <iostream>
#include <iterator>
int main()
{
    char arr[]{"ababbbabaabaababaababaaaabaaba"};
    const int length{ static_cast<int>(std::size(arr)) };
    int n = 0;
    for (int i = 0; i <= length-2; i++) {
        if (arr[i] == 'a' && arr[i + 1] == 'b' && arr[i + 2] == 'a') n++;
    }
    std::cout << n;
}