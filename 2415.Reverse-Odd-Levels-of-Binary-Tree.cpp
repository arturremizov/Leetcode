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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int level = 0;
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<TreeNode*> levelVector;
            while (levelSize--) {
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
                if (level % 2 == 1) {
                    levelVector.push_back(node);
                }
            }
            
            if (level % 2 == 1) {
                int left = 0, right = levelVector.size() - 1;
                while (left < right) {
                    int temp = levelVector[left]->val;
                    levelVector[left]->val = levelVector[right]->val;
                    levelVector[right]->val = temp;
                    ++left, --right;
                }
            }

            ++level;
        }
        return root;
    }
};

int main() {
    Solution solution; 
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3, new TreeNode(8), new TreeNode(13));
    root->right = new TreeNode(5, new TreeNode(21), new TreeNode(34));
    TreeNode* result = solution.reverseOddLevels(root);
}