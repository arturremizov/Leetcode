#include <iostream>
#include <string>

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        dfs(root, startPath, startValue);
        dfs(root, destPath, destValue);
        int i = 0;
        while (i < min(startPath.length(), destPath.length())) {
            if (startPath[i] != destPath[i]) break;
            ++i;
        }
        string start(startPath.length() - i, 'U');
        destPath.erase(0, i);  
        return start + destPath;      
    }
private:
    bool dfs(TreeNode* node, string& path, int targetValue) {
        if (node == NULL) return false;
        if (node->val == targetValue) return true;

        path.append("L");
        if (dfs(node->left, path, targetValue)) return true;
        path.pop_back();

        path.append("R");
        if (dfs(node->right, path, targetValue)) return true;
        path.pop_back();
        return false;
    }
};

int main() 
{
    Solution solution; 
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1, new TreeNode(3), NULL);
    root->right = new TreeNode(2, new TreeNode(6), new TreeNode(4));
    cout << solution.getDirections(root, 3, 6) << endl; // UURL
}