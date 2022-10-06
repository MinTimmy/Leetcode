#include <vector>
#include <iostream>
#include <functional>

using graph_data_type = std::vector<std::vector<int>>;
// typedef std::vector<std::vector<int>> graph_data_type;

class Solution {
public:
    graph_data_type getAncestors(int n, graph_data_type& edges) {
        graph_data_type ans(n);
        graph_data_type g(n);

        for (const auto& e : edges){
            g[e[0]].push_back(e[1]);
        }

        std::function<void(int, int)> dfs = [&](int s, int u) -> void{
            for (const auto& v : g[u]){
            // for (int v : ans[u]){
                if(ans[v].empty() || ans[v].back() != s){
                    ans[v].push_back(s);
                    dfs(s, v);
                }
            }
        };
        for(int i = 0; i < n; i++){
            dfs(i, i);
        }

        return ans;
    }
};


int main()
{
    int n = 8;
    graph_data_type edgeList{
        std::vector<int> {0,3},
        std::vector<int> {0,4},
        std::vector<int> {1,3},
        std::vector<int> {2,4},
        std::vector<int> {2,7},
        std::vector<int> {3,5},
        std::vector<int> {3,6},
        std::vector<int> {3,7},
        std::vector<int> {4,6}
    };

    Solution s;
    graph_data_type ans = s.getAncestors(n, edgeList);

    for (const auto& i : ans){
        for (const auto& j : i){
            std::cout << j << " ,";
        }
        std:: cout << '\n';
    }
}