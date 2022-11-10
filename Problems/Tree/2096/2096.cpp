#include <string>
#include <algorithm>

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
    std::string getDirections(TreeNode* root, int startValue, int destValue) {
        std::string startPath;
        std::string destPath;

        build_path(root, startValue, startPath);
        build_path(root, destValue, destPath);

        // Remove common suffix (shared path from root to LCA)
        while( !startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()){
            startPath.pop_back();
            destPath.pop_back();
        }

        std::reverse(destPath.begin(), destPath.end());
        return std::string(startPath.size(), 'U') + destPath;
    }

private:
    bool build_path(TreeNode* root, int target_num, std::string& path){
        if (root == nullptr) return false;

        if (target_num == root->val) return true;

        if (build_path(root->left, target_num, path)){
            path.push_back('L');
            return true;
        }
        if (build_path(root->right, target_num, path)){
            path.push_back('R');
            return true;
        }

        return false;
        
    }
};