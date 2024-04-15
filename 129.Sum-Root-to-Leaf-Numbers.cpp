#include <iostream>
#include <stack>

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
    int sumNumbers(TreeNode* root) {
        int result = 0;
        stack<pair<TreeNode *, int>> stack; // node, current num
        stack.push(make_pair(root, 0));

        while (!stack.empty()) {
            TreeNode *node = stack.top().first;
            int num = stack.top().second * 10 + node->val;
            stack.pop();
            if (node->left == NULL && node->right == NULL) {
                result += num;
                continue;
            } 
            if (node->right != NULL) {
                auto pair = make_pair(node->right, num);
                stack.push(pair);
            }  
            if (node->left != NULL) {
                auto pair = make_pair(node->left, num);
                stack.push(pair);
            }
        }
        return result;
    }
};

int main() 
{
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Solution solution; 
    cout << solution.sumNumbers(root) << endl;
}