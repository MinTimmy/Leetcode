#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Solution {
public:
    int edgeScore(std::vector<int>& edges) {
        const int n = edges.size();
        std::vector<long> s(n);

        for(int i = 0; i < n; i++){
          s[edges[i]] += i;
        }
        return std::max_element(s.begin(), s.end()) - s.begin();
    }
};


int main()
{
    int a[] = {1,0,0,0,0,7,7,5};
    std::vector<int> edges(a, a + sizeof(a) / sizeof(int));
    // std::vector<int> edges{1,0,0,0,0,7,7,5};
     
    Solution S;
    std::cout << S.edgeScore(edges);
}