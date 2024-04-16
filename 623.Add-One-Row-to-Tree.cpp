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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *node = new TreeNode(val, root, NULL);
            return node;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        int currentLevel = 1;
        while (!queue.empty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode *node = queue.front();
                queue.pop();
                if (currentLevel == depth - 1) {
                    node->left = new TreeNode(val, node->left, NULL);
                    node->right = new TreeNode(val, NULL, node->right);
                } else {
                    if (node->left) queue.push(node->left);
                    if (node->right) queue.push(node->right);
                }
            }
            currentLevel++;
        }
        return root;
    }
};

int main() 
{
    TreeNode* left = new TreeNode(2, new TreeNode(3), new TreeNode(1));
    TreeNode* right = new TreeNode(6, new TreeNode(5), NULL);
    TreeNode* root = new TreeNode(4, left, right);
    Solution solution; 
    TreeNode* result = solution.addOneRow(root, 1, 2);
}