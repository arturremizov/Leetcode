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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int result = 0;
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            result = root->left->val;
        } else {
            result += sumOfLeftLeaves(root->left);
        }
        return result + sumOfLeftLeaves(root->right);
    }
};

int main() 
{
    TreeNode* left = new TreeNode(9);
    TreeNode* right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    TreeNode* root = new TreeNode(3, left, right);

    Solution solution; 
    cout << solution.sumOfLeftLeaves(root) << endl;
}