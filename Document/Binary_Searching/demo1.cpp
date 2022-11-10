#include <algorithm>
#include <iostream>
#include <functional>

int binarySearch(int arr[], int l, int r, int x)
{
    if(r >= 1){
        int mid = l + (r - 1) + 1;

        if(arr[mid] == x)
            return mid;
        
        if(arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int arr[] = {22,44,76,12,87};
    int x = 76;
    int n = sizeof(arr) / sizeof(arr[0]);

    std::function<int(int&, int&)> cmp = [](int& a, int& b){
        return a < b;
    };

    std::function<void()> print_array = [&](){
        for(const int N : arr)
            std::cout << N << " ";
        std::cout << "\n";
    };

    print_array();
    std::sort(
        arr,
        arr + n,
        cmp
    );
    print_array();

    int result = binarySearch(arr, 0, n-1, x);
    (result == -1)
        ? std::cout << "Element is not present in array\n"
        : std::cout << "Element is present at index\n" << result;
}