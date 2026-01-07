#include <iostream>
#include <queue>
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
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9+7;
        const int totalSum = dfs(root);
        queue<TreeNode *> queue;
        queue.push(root);
        long long result = 0;
        while (!queue.empty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode *node = queue.front();
                queue.pop();
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
                long long curProduct = (1LL * (totalSum - node->val) * node->val);
                result = max(result, curProduct);
            }
        }
        return result % MOD;
    }
private:
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        root->val = root->val + dfs(root->left) + dfs(root->right);
        return root->val; 
    }
};

int main() {
    Solution solution; 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3, new TreeNode(6), nullptr);
    cout << solution.maxProduct(root) << endl; // 110
}