#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <functional>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
    
        std::unordered_set<int> hasParent;

        // root's value, <left's value, right's value>
        std::unordered_map<int, std::pair<int, int>> children;

        for(const auto& d : descriptions){
            hasParent.insert(d[1]);
            (d[2] ? children[d[0]].first : children[d[0]].second) = d[1];
        }

        
        int root = -1;
        // find which node is the root
        for(const auto& d : descriptions)
            if(!hasParent.count(d[0])) root = d[0];

        std::function<TreeNode*(int)> build = [&](int cur) -> TreeNode*{
            if(!cur) return nullptr;
            return new TreeNode(
                cur, 
                build(children[cur].first),
                build(children[cur].second)
            );
        };
        return build(root); 
    }
};

int main()
{
    std::vector<std::vector<int>> descriptions = {
        {20,15,1},
        {20,17,0},
        {50,20,1},
        {50,80,0},
        {80,19,1}
    };

    Solution* S = new Solution();
    S->createBinaryTree(descriptions);
}