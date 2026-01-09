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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
private: 
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (root == nullptr) return {0, nullptr};

        auto [leftDepth, leftNode] = dfs(root->left);
        auto [rightDepth, rightNode] = dfs(root->right);

        if (leftDepth == rightDepth) {
            return {leftDepth + 1, root};
        } else if (leftDepth > rightDepth) {
            return {leftDepth + 1, leftNode};
        } else {
            return {rightDepth + 1, rightNode};
        }
    }
};

int main() {
    Solution solution; 
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2, new TreeNode(7), new TreeNode(4));
    root->right = new TreeNode(1, new TreeNode(0), new TreeNode(8));
    cout << solution.subtreeWithAllDeepest(root)->val << endl; // 2
}