#include <iostream>
#include <functional>

void fillPrefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i-1] + arr[i];
}

int main()
{
    int arr[] = {10, 4, 16, 20};
    int n = sizeof(arr) / sizeof(int);
    int prefixSum[n] = {0,0,0,0};

    // fillPrefixSum(arr, n, prefixSum);

    std::function<void(int [], int)> print_nums = [&](int inside_arr[], int n){
        for (int i = 0; i < n; i++){
            std::cout << inside_arr[i] << " ";
        }
        std::cout << '\n';
    };

    print_nums(arr,n);
    fillPrefixSum(arr, n, prefixSum);
    print_nums(prefixSum,n);
    return 0;    

}