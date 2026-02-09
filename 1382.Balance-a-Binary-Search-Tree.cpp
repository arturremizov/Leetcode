#include <iostream>
#include <vector>
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrderNodeValues;
        dfs(root, inOrderNodeValues);
        return makeBalanceBST(0, inOrderNodeValues.size() - 1, inOrderNodeValues);
    }
private:
    void dfs(TreeNode* root, vector<int>& nodeValues) {
        if (root == nullptr) return;
        dfs(root->left, nodeValues);
        nodeValues.push_back(root->val);
        dfs(root->right, nodeValues);
    }
    TreeNode* makeBalanceBST(int left, int right, const vector<int>& nodeValues) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nodeValues[mid]);
        root->left = makeBalanceBST(left, mid - 1, nodeValues);
        root->right = makeBalanceBST(mid + 1, right, nodeValues);
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    Solution solution;
    TreeNode* result = solution.balanceBST(root);
}