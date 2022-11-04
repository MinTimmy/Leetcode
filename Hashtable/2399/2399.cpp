#include<iostream>
#include <vector>
#include <string>
#include <iomanip>
class Solution {
public:
    bool checkDistances(std::string s, std::vector<int>& distance) {
        std::vector<int> m(26, -1);
        for(int i = 0; i < s.length(); i++){
            int c = s[i] - 'a';
            if(m[c] >= 0 && i - m[c] - 1 != distance[c]) return false;
            m[c] = i;
        }        
        return true;
    }
};

int main()
{
    std::string s = "aa";
    int d[] = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> distance(d, d + sizeof(d) / sizeof(int));
    Solution sol;
    std::cout << std::boolalpha << sol.checkDistances(s, distance);
}
