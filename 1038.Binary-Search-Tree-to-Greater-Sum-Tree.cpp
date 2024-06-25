#include <iostream>

using namespace std;

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
    TreeNode* bstToGst(TreeNode* root) {
        int nodeSum = 0;
        reverseInOrderDfs(root, nodeSum);
        return root;
    }
private:
    void reverseInOrderDfs(TreeNode* root, int& nodeSum) {
        if (root == NULL) return;
        reverseInOrderDfs(root->right, nodeSum);
        nodeSum += root->val;
        root->val = nodeSum;
        reverseInOrderDfs(root->left, nodeSum);
    }
};

int main() 
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1, new TreeNode(0), new TreeNode(2));
    root->left->right->right = new TreeNode(3);

    root->right = new TreeNode(6, new TreeNode(5), new TreeNode(7));
    root->right->right->right = new TreeNode(8);

    Solution solution;
    TreeNode* newRoot = solution.bstToGst(root);
}