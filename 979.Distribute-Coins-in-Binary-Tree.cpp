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
    int result = 0;
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return result;
    }
private:
    pair<int, int> dfs(TreeNode* node) {
        if (node == NULL) return {0,0};
        auto leftResult = dfs(node->left);
        auto rightResult = dfs(node->right);
        int size = 1 + leftResult.first + rightResult.first;
        int coins = node->val + leftResult.second + rightResult.second;
        result += abs(size - coins);
        return {size, coins};
    }
};

int main() 
{
    TreeNode* root = new TreeNode(3, new TreeNode(0), new TreeNode(0));
    Solution solution; 
    cout << solution.distributeCoins(root) << endl; // 2
}