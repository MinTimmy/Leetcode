#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return  nullptr; // if the inpurt is NULL, return nullptr
        std::unordered_map<Node*, Node*> m; // the answer graph we will creat
        std::function<void(Node*)> dfs = [&](Node* u){
            m[u] = new Node(u->val);
            for (Node* v : u->neighbors){
                if(!m.count(v)) dfs(v); // if we find the node v in m, we do dfs
                m[u]->neighbors.push_back(m[v]);
            }
        };
        dfs(node);
        return m[node];     
    }
};


int main()
{

}