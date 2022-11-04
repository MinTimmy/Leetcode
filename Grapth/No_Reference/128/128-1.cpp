#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class solution{
    public:
        int longestConsecutive(std::vector<int>& nums){
            if(nums.empty()) return 0;
            std::unordered_set<int> hset(nums.begin(), nums.end());
            int maxLCS = INT_MIN;

            for (const auto& num: nums){
                if(hset.count(num) != 0) {
                    hset.erase(num);
                    int next = num + 1, pre = num - 1;
                    while(hset.count(next) != 0) hset.erase(next++);
                    while(hset.count(pre) != 0) hset.erase(pre--);
                    maxLCS = std::max(next-pre-1, maxLCS);
                }
            }
            return maxLCS;
        }
};

int main()
{
    solution s;
    std::vector<int> array{100,4,200,1,3,2};
    std::cout << s.longestConsecutive(array);
}