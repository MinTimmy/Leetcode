
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        if(l == r)
            return (1 << l) + countNodes(root->right);
        else
            return (1 << (l-1)) + countNodes(root->left);
    }

private:
    int depth(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + depth(root->left);
    }
};

int main()
{

}