#include <iostream>
#include <iterator>
int main()
{
    char arr[]{"abababababbbbabaaaaaaaabbbbaabababababbbb"};
    const int length{ static_cast<int>(std::size(arr)) };
    int n = 0;
    for (int i = 0; i <= length-1; i++) {
        if (arr[i] == 'a') arr[i] = 'A';
        if (arr[i] == 'b') arr[i] = 'B';
    }
    std::cout << arr;

    return 0;
}
