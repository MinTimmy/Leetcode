#include <algorithm>
#include <iostream>
#include <functional>

int main()
{
    int arr[] = { 5,2,1,4,3};

    
    std::sort(arr, arr + sizeof(arr)/sizeof(arr[0]), [](int& a, int& b){
        return a > b;
    });

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}