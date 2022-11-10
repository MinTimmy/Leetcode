#include <vector>
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

// By using pre-order traversal, the right most node will be the last one to visit in each level.
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ans;

         std::function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int d){
            if (root == nullptr) return;
            if (ans.size() < d + 1) ans.push_back(0);
            ans[d] = root->val;
            dfs(root->left, d + 1);
            dfs(root->right, d + 1);
         };
         dfs(root, 0);
         return ans;
    }
};