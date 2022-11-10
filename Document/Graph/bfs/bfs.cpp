#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
// Reference: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

void bfs_traversal(std::unordered_map<int, std::vector<int>>& m, int num_of_node)
{
    std::list<int> queue;
    std::vector<bool> visited;
    visited.resize(num_of_node, false);

    queue.push_back(0);

    while(!queue.empty()){
        int pNode = queue.front();
        std::cout << pNode << " ";
        visited[pNode] = true;

        queue.pop_front();

        for (const int child : m[pNode]){
            if (!visited[child])
                queue.push_back(child);
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

    bfs_traversal(m, 6);

}