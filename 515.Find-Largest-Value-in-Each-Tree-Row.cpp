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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> queue;
        if (root) queue.push(root);
        while (!queue.empty()) {
            int levelSize = queue.size();
            int currentMax = INT32_MIN;
            while (levelSize--) {
               TreeNode* node = queue.front();
               queue.pop();
               currentMax = max(currentMax, node->val);
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            result.push_back(currentMax);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3, new TreeNode(5), new TreeNode(3));
    root->right = new TreeNode(2, nullptr, new TreeNode(9));

    vector<int> result = solution.largestValues(root); // [1,3,9]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}