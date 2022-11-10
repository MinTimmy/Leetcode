
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
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};

int main()
{
    TreeNode* root = new TreeNode(10);
    TreeNode* left = new TreeNode(4);
    TreeNode* right = new TreeNode(6);

    root->left = left;
    root->right = right;

    Solution* S = new Solution();
    S->checkTree(root);
}