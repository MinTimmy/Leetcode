#include <algorithm>
#include <iostream>
#include <functional>

int main()
{
    int arr[] = { 5,2,1,4,3};

    std::function<void()> print_array = [&](){
        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    };
    std::function<int(int&, int &)> cmp = [](int& a, int& b){
        return a > b;
    };

    print_array();
    std::sort(
        arr, 
        arr + sizeof(arr)/sizeof(arr[0]), 
        cmp
    );
    print_array();
   
    return 0;
}