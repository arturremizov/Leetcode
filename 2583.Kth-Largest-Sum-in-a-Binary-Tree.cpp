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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode *> queue;
        queue.push(root);
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        while (!queue.empty()) {
            int levelSize = queue.size();
            long long levelSum = 0;
            for (int i = 0; i < levelSize; i++) {
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
            minHeap.push(levelSum);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.size() == k ? minHeap.top() : -1;
    }
};

int main() {
    Solution solution; 
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(2, new TreeNode(4), new TreeNode(6));
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(9, new TreeNode(3), new TreeNode(7));

    cout << solution.kthLargestLevelSum(root, 2) << endl; // 13
}