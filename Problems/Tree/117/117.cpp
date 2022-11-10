#include <unordered_map>
#include <vector>
#include <iostream>
#include <list>
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        std::list<Node*> queue;
        queue.push_back(root);
        while(!queue.empty()){
            int size = queue.size();
            Node* p = nullptr;

            while(size--){
                Node* t = queue.front();
                queue.pop_front();
                if (p)
                    p->next = t, p = p->next;
                else
                    p = t;
                if(t->left) queue.push_back(t->left);
                if(t->right) queue.push_back(t->right);
            }
        }
        return root;
    }
};

int main()
{
    Node* root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution* S = new Solution();
    S->connect(root);
}