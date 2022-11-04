#include <vector>
#include <iostream>
#include <functional>
#include <tuple>

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
    int averageOfSubtree(TreeNode* root) {
        std::function<std::tuple<int, int, int>(TreeNode*)> getSum 
            = [&](TreeNode* root)-> std::tuple<int, int, int>{
                if(!root) return {0,0,0};
                auto [lv, lc, la] = getSum(root->left);
                auto [rv, rc, ra] = getSum(root->right);
                int sum = lv + rv + root->val;
                int count = lc + rc + 1;
                int ans = la + ra + (root->val == sum / count);
                return {sum, count, ans};
            }        
            return get<2>getSum(root);
    }
};


TreeNode* make_noda(TreeNode* pNode, int num)
{

}
int main()
{
   std::vector<int> nums = {4,8,5,0,1,-1,6};
}