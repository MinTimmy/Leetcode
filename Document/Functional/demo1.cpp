#include <iostream>
#include <vector>
#include <functional>

// https://www.geeksforgeeks.org/recursive-lambda-expressions-in-cpp/
// https://ithelp.ithome.com.tw/articles/10215320
int main()
{
    int n = 12345;
    int m = 6666;
    std::function<void()> printReverse = [&](){
        if (n == 0)
            return;
        // std::cout << "m " << m << '\n';
        // Defination
        std::cout << n % 10 << " ";
        n /= 10;
        printReverse(); 
    };

    printReverse();
}