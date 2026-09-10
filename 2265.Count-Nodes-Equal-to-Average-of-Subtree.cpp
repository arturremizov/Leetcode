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
    int averageOfSubtree(TreeNode* root) {
        int averageCount = 0;
        postOrderDfs(root, averageCount);
        return averageCount;
    }
private:
    pair<int, int> postOrderDfs(TreeNode* node, int& averageCount) {
        if (node == nullptr) return {0, 0};
        auto [leftSum, leftNodeCount] = postOrderDfs(node->left, averageCount);
        auto [rightSum, rightNodeCount] = postOrderDfs(node->right, averageCount);
        int sum = leftSum + rightSum + node->val;
        int nodeCount = leftNodeCount + rightNodeCount + 1;
        int value = sum / nodeCount;
        if (value == node->val) ++averageCount;
        return {sum, nodeCount};
    }
};

int main() {
    Solution solution; 
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(8, new TreeNode(0), new TreeNode(1));
    root->right = new TreeNode(5, nullptr, new TreeNode(6));
    cout << solution.averageOfSubtree(root) << endl; // 5
}