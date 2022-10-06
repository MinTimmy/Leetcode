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
        std::vector<std::vector<int>>g(n);
        for (const auto& edge: edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        std::vector<int> seen(n);
        long long counter = 0;
        std::function<void(int)> dfs = [&](int v) {
            ++counter;
            for (int u: g[v])
                if(seen[u]++ == 0) dfs(u);
        };
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(seen[i]++) continue;
            counter = 0;
            dfs(i);
            ans += (n - counter) * counter;
            std::cout << i << "  ans " << ans << '\t' << "counter " << counter << '\n';
        }
        return ans / 2;
    }

};
class Solution_2 {
public:
  long long countPairs(int n, std::vector<std::vector<int>>& edges) {
    std::vector<int> parents(n);
    std::vector<int> counts(n, 1);

    std::iota(begin(parents), end(parents), 0);

    std::function<int(int)> find = [&](int v){
      if(parents[v] == v) return v;
      return parents[v] = find(parents[v]);
    };


    for(const auto& e: edges){
      int ru = find(e[0]);
      int rw = find(e[1]);

      if(ru != rw){
        parents[rw] = ru;
        counts[ru] += counts[rw];
      }
    }
    long long ans = 0;

    for (int i = 0; i < n; i++){
      ans += n - counts[find(i)];
    }
    return ans / 2;
    
  }
};
int main()
{
    Solution_1 s_1;
    Solution_2 s_2;
    std::vector<std::vector<int>> edges {
        std::vector<int>{0,2},
        std::vector<int>{0,5},
        std::vector<int>{2,4},
        std::vector<int>{1,6},
        std::vector<int>{5,4}
    };
    int n = 7;
    std::cout << s_1.countPairs(n, edges) << "\n";
    std::cout << s_2.countPairs(n, edges) << "\n";
}