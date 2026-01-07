#include <iostream>
#include <queue>
#include <climits>
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
    int maxLevelSum(TreeNode* root) {
        int result = 0;
        int curLevel = 1;
        int maxSum = INT_MIN;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int levelSum = 0;
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode *node = queue.front();
                queue.pop();
                levelSum += node->val;
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            if (levelSum > maxSum) {
                maxSum = levelSum;
                result = curLevel;
            }
            ++curLevel;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7, new TreeNode(7), new TreeNode(-8));
    root->right = new TreeNode(0);
    cout << solution.maxLevelSum(root) << endl; // 2
}