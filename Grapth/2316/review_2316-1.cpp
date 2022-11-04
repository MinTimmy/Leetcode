//https://zxi.mytechroad.com/blog/category/graph/

#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

// using namespace std;

//Solution 1: DFS
class Solution_1 {
public:
    long long countPairs(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> g(n);
        for (auto edge : edges){
          g[edge[0]].push_back(edge[1]);
          g[edge[1]].push_back(edge[0]);
        }
        std::vector<int> seen(n);
        long long ans = 0;
        long long counter = 0;

        std::function<void(int)> dfs = [&](int v){
          counter++;
          for(int u : g[v]){
            if(seen[u]++ == 0) dfs(u);
          }
        };

        for (int i = 0; i < n; i++){
          if(seen[i]++) continue;
          counter = 0;
          dfs(i);
          ans += (n - counter) * counter;
        }
        ans /= 2;
        return ans;
    }

};
int main()
{
    Solution_1 s_1;
    std::vector<std::vector<int>> edges {
        std::vector<int>{0,2},
        std::vector<int>{0,5},
        std::vector<int>{2,4},
        std::vector<int>{1,6},
        std::vector<int>{5,4}
    };
    int n = 7;
    std::cout << s_1.countPairs(n, edges) << "\n";
}