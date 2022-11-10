#include <iostream>
#include <vector>
#include <map>


class Solution {
public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>>& flowers, std::vector<int>& persons) {
        std::map<int, int> m {{0, 0}};

        for (const auto& f : flowers)
            ++m[f[0]], --m[f[1]+1];
            // ++m[f[0]], --m[f[1] + 1];    

        int sum = 0;
        std::vector<int> ans;
        for(std::map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++){
            iter->second = sum += iter->second;
        }
        // for(std::map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++){
        //     std::cout << iter->first << " " << iter->second << std::endl;
        // }
        for (int t : persons)
            ans.push_back(std::prev(m.upper_bound(t)) -> second);
        
        // for(int num : ans)
        //     std::cout << num << " ";
        return ans;
    }
};

int main()
{
    std::vector<std::vector<int>> flowers = {
        std::vector<int> {1,6},
        std::vector<int> {3,7},
        std::vector<int> {9,12},
        std::vector<int> {4,13}
    };
    
    
    std::vector<int> persons = {2,3,7,11};

    Solution* S = new Solution();

    S->fullBloomFlowers(flowers, persons);
}