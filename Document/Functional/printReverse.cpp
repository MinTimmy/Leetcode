#include <iostream>
#include <functional>

int main()
{
    int n = 12345;


    auto print_reserve = [](int n, auto print_reserve){
        if(n == 0)
            return;
        std::cout << n % 10 << " ";
        n /= 10;
        print_reserve(n, print_reserve);    
    };

    print_reserve(n, print_reserve);
    std::cout << "\nFinial n = " << n << "\n";

    return 0;
}