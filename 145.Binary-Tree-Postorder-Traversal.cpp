#include <iostream>
#include <vector>

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postOrder(root, result);
        return result;
    }
private:
    void postOrder(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }
};

int main() {
    Solution solution; 

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2, new TreeNode(3), NULL);

    vector<int> result = solution.postorderTraversal(root); // [3,2,1]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}