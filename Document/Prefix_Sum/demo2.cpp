#include <vector>
#include <iostream>

void fillPrefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i-1] + arr[i];
}

int main()
{
    int arr[] = {3, 6, 2, 8, 9, 2};
    int n = sizeof(arr) / sizeof(int);
    int prefixSum[n];

    fillPrefixSum(arr, n, prefixSum);

    std::vector<std::vector<int>> query = {
        {2,3},
        {4,6},
        {1,5},
        {3,6}
    };

    for(int i = 0; i < query.size(); i++){
        int l = query[i][0], r = query[i][1];

        std::cout << l << "~" << r << ": ";
        if (r > n || l < 1) {
            std::cout << "Please input in range 1 to " << n
                 << std::endl;
            continue;
        }

        if (l == 1)
            std::cout << prefixSum[r-1] << std::endl;
        else
            std::cout << prefixSum[r-1] - prefixSum[l - 2] << std::endl;
    }
}