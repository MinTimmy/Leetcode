#include <unordered_map>
#include <vector>
#include <iostream>

void explore(std::unordered_map<int, std::vector<int>>& m, std::vector<bool>& visited, int v)
{
    visited[v] = true;

    for (const int child : m[v]){
        if (!visited[child]){
            std::cout << child << " ";
            explore(m, visited, child);
        }
    }
}

void dfs_traversal(std::unordered_map<int, std::vector<int>>& m, int num_of_node)
{
    std::vector<bool> visited;
    visited.resize(num_of_node, false);

    for (int v = 0; v < num_of_node; v++){
        if (!visited[v]){
            std::cout << v << " ";
            explore(m, visited, v);
        }
    }
}

int main()
{
    std::unordered_map<int, std::vector<int>> m;

    //textbook page 106
    m[0] = std::vector<int> {0,1,3,4,5}; // S
    m[1] = std::vector<int> {0,1,2};     // A
    m[2] = std::vector<int> {1};         // B
    m[3] = std::vector<int> {0};         // C
    m[4] = std::vector<int> {0};         // D
    m[5] = std::vector<int> {0};         // E

    dfs_traversal(m, 6);
}