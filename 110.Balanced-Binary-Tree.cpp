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
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
private:
    pair<int, bool> dfs(TreeNode* root) {
        if (root == nullptr) return {0, true};

        auto [leftHeight, leftBalanced] = dfs(root->left);
        auto [rightHeight, rightBalanced] = dfs(root->right);

        bool isBalanced = true;
        if (!leftBalanced || !rightBalanced || abs(leftHeight - rightHeight) > 1) {
            isBalanced = false;
        }
        
        return {max(leftHeight, rightHeight) + 1, isBalanced};
    }
};

int main() {
    Solution solution; 
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    cout << solution.isBalanced(root) << endl; // true
}