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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return root1 == nullptr && root2 == nullptr;
        }
        if (root1->val != root2->val) return false;

        int result1 = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        int result2 = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        return result1 || result2;
    }
};

int main() {
    Solution solution; 
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(7), new TreeNode(8)));
    root1->right = new TreeNode(3, new TreeNode(6), nullptr);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3, nullptr, new TreeNode(6));
    root2->right = new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(8), new TreeNode(7)));

    cout << solution.flipEquiv(root1, root2) << endl; // true
}