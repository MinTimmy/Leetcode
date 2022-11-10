#include<vector>
#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
};
/* Function prototypes */
TreeNode* newNode(int data);
void printLevelOrder(TreeNode* root);
void make_bredth_first_tree(TreeNode* root, std::vector<int> nums);

void make_bredth_first_tree(TreeNode* root, std::vector<int> nums){
    // Base Case
    if (root == NULL)
        return;
 
    TreeNode* pNode = root;

    // Create an empty queue for level order traversal
    std::queue<TreeNode*> q;
    q.push(pNode);
 
    for (int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << '\n';
         // Print front of queue and remove it from queue
        TreeNode* node = q.front();
        q.pop();
        node->val = nums[i];

        /* Enqueue left child */
        if(q.size() < nums.size() - i - 1){
            node->left = new TreeNode();
            q.push(node->left);
        }
    
 
        /*Enqueue right child */
        if(q.size() < nums.size() - i - 1){
            node->right = new TreeNode();
            q.push(node->right);
        }
    }
    
}
 
/// Iterative method to find height of Binary Tree
void printLevelOrder(TreeNode* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    std::queue<TreeNode*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
    int counter = 0;
    int border = 1;
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        TreeNode* node = q.front();

        if(counter++ == border){
            std::cout << '\n';
            border *= 2;
            counter = 1;
        }
        std::cout << node->val << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}
 
 
/* Helper function that allocates
a new node with the given data and
NULL left and right pointers. */
TreeNode* newNode(int data)
{
    TreeNode* Node = new TreeNode();
    Node->val = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}
 
/* Driver code*/
// int main()
// {
//     // TreeNode* root = newNode(1);
//     // root->left = newNode(2);
//     // root->right = newNode(3);
//     // root->left->left = newNode(4);
//     // root->left->right = newNode(5);

//     TreeNode* root = new TreeNode();
//     std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
//     make_bredth_first_tree(root,nums);
 
//     std::cout << "Level Order traversal of binary tree is \n";
//     printLevelOrder(root);
 
//     return 0;
// }