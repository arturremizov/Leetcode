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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
private:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (node == nullptr) return {0, nullptr};

        auto [leftHeight, leftNode] = dfs(node->left);
        auto [rightHeight, rightNode] = dfs(node->right);

        if (leftHeight == rightHeight) {
            return {leftHeight + 1, node};
        } else if (leftHeight > rightHeight) {
            return {leftHeight + 1, leftNode};
        } else {
            return {rightHeight + 1, rightNode};
        }
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5, new TreeNode(6), new TreeNode(2));
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1, new TreeNode(0), new TreeNode(8));

    Solution solution; 
    cout << solution.lcaDeepestLeaves(root)->val << endl; // 2
}