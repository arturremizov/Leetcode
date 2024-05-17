#include <iostream>
#include <stack>
#include <unordered_set>
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        stack<TreeNode*> stack;
        stack.push(root);
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] = NULL;
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            if (!node->left && !node->right) {
                if (node->val == target) {
                    TreeNode* parrent = parents[node];
                    if (parrent == NULL) {
                        return NULL;
                    }
                    if (parrent->left == node) {
                        parrent->left = NULL;
                    }
                    if (parrent->right == node) {
                        parrent->right = NULL;
                    }
                }
            } else if (!visited.count(node)) {
                visited.insert(node);
                stack.push(node);
                if (node->left) {
                    stack.push(node->left);
                    parents[node->left] = node;
                }
                if (node->right) {
                    stack.push(node->right);
                    parents[node->right] = node;
                }
            }
        }
        return root;
    }
    // TreeNode* removeLeafNodes(TreeNode* root, int target) {
    //     if (!root) return NULL;
    //     root->left = removeLeafNodes(root->left, target);
    //     root->right = removeLeafNodes(root->right, target);
    //     if (!root->left && !root->right && root->val == target) {
    //         return NULL;
    //     }
    //     return root;
    // }
};

int main() 
{
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(2), NULL), new TreeNode(3, new TreeNode(2), new TreeNode(4)));
    Solution solution; 
    TreeNode *result = solution.removeLeafNodes(root, 2);
}