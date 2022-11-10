#include <iostream>
#include <vector>
#include <unordered_map>


class Solution {
public:
    int mostFrequentEven(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        int ans = -1;
        int best = 0;

        for (int x : nums){
            if(x & 1) continue;
            int cur = m[x] + 1;
            if(cur > best){
                ans = x;
                best = cur;
            }
            else if (best == cur && x < ans){
                ans = x;
            }
        }    
        return ans;    
    }
};

int main()
{
    int n[] = {0,1,2,2,4,4,1};
    std::vector<int> nums(n, n + sizeof(n) / sizeof(int));
    Solution s;
    std::cout << s.mostFrequentEven(nums);
}