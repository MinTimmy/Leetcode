#include <iostream>
#include <functional>

int main()
{
    auto factorial = [](int n, auto factorial){
        std::cout << n << '\n';
        if (n == 1){
            std::cout << "end\n";
            return n;
        }
        return n * factorial(n - 1, factorial);
    };

    // std::cout << "ans: ";
    std::cout << factorial(3, factorial);
}