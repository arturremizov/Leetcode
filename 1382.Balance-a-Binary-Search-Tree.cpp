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
        vector<int> nodes;
        inOrderDfs(root, nodes);
        return buildBalanceBST(nodes, 0, nodes.size() - 1);
    }
private:
    void inOrderDfs(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) return;
        inOrderDfs(root->left, nodes);
        nodes.push_back(root->val);
        inOrderDfs(root->right, nodes);
    }
    TreeNode* buildBalanceBST(const vector<int>& nodes, int left, int right) {
        if (left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = buildBalanceBST(nodes, left, mid - 1);
        node->right = buildBalanceBST(nodes, mid + 1, right);
        return node;
    }
};

int main() 
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution solution;
    TreeNode* newRoot = solution.balanceBST(root);
}