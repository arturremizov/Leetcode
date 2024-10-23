#include <iostream>
#include <vector>
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSum;

        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int levelSize = queue.size();
            int currentSum = 0;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                currentSum += node->val;
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            levelSum.push_back(currentSum);
        }

        queue.push(root);
        root->val = 0;
        int level = 0;
        while (!queue.empty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                int childSum = 0;
                if (node->left) {
                    childSum += node->left->val;
                }
                if (node->right) {
                    childSum += node->right->val;
                }
                if (node->left) {
                    queue.push(node->left);
                    node->left->val = levelSum[level + 1] - childSum;
                }
                if (node->right) {
                    queue.push(node->right);
                    node->right->val = levelSum[level + 1] - childSum;
                }
            }
            ++level;
        }
        return root;
    }
};

int main() {
    Solution solution; 
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4, new TreeNode(1), new TreeNode(10));
    root->right = new TreeNode(9, nullptr, new TreeNode(7));

    TreeNode* result = solution.replaceValueInTree(root);
}