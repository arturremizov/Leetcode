#include <iostream>

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
    string helper(TreeNode* root, string current) {
        if (root == NULL) return "";
        current = char(int('a') + root->val) + current;
        if (root->left && root->right) {
            return min(
                helper(root->left, current),
                helper(root->right, current)
            );
        } 
        if (root->left) {
            return helper(root->left, current);
        }
        if (root->right) {
            return helper(root->right, current);
        }         
        return current;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        return helper(root, "");
    }
};

int main() 
{
    TreeNode* left = new TreeNode(1, new TreeNode(3), new TreeNode(4));
    TreeNode* right = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    TreeNode* root = new TreeNode(0, left, right);
    Solution solution; 
    cout << solution.smallestFromLeaf(root) << "\n";
}