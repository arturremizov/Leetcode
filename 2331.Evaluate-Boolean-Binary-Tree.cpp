#include <iostream>
#include <stack>
#include <unordered_map>

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
    bool evaluateTree(TreeNode* root) {
        stack<TreeNode *> stack;
        stack.push(root);
        unordered_map<TreeNode*, int> values; // node -> value
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            if (!node->left && !node->right) {
                values[node] = node->val;
            } else {
                if (values.count(node->left) && values.count(node->right)) {
                    if (node->val == 2) {
                        values[node] = values[node->left] || values[node->right];
                    } 
                    if (node->val == 3) {
                        values[node] = values[node->left] && values[node->right];
                    }
                } else {
                    stack.push(node);
                    stack.push(node->left);
                    stack.push(node->right);
                }
            }
        }
        return values[root];
    }

    // bool evaluateTree(TreeNode* root) {
    //     if (!root->left && !root->right) return root->val;
    //     if (root->val == 2) {
    //         return evaluateTree(root->left) || evaluateTree(root->right);
    //     }
    //     return evaluateTree(root->left) && evaluateTree(root->right);
    // }
};

int main() 
{
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3, new TreeNode(0), new TreeNode(1)));
    Solution solution; 
    cout << solution.evaluateTree(root) << endl; // true
}