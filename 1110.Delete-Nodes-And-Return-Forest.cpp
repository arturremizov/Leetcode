#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        unordered_set<TreeNode *> result_set;
        result_set.insert(root);
        dfs(root,to_delete_set, result_set);
        vector<TreeNode *>result(result_set.begin(), result_set.end());
        return result;
    }
private:
    TreeNode* dfs(TreeNode* node, unordered_set<int>& to_delete_set, 
                                  unordered_set<TreeNode *>& result_set) {
        if (node == NULL) return NULL;
        TreeNode* result = node;
        if (to_delete_set.count(node->val)) {
            result = NULL;
            result_set.erase(node);
            if (node->left) result_set.insert(node->left);
            if (node->right) result_set.insert(node->right);
        }
        node->left = dfs(node->left, to_delete_set, result_set);
        node->right = dfs(node->right, to_delete_set, result_set);
        return result;
    }
};

int main() 
{
    Solution solution; 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
    vector<int> to_delete = {3,5};
    vector<TreeNode*> result = solution.delNodes(root, to_delete);
}