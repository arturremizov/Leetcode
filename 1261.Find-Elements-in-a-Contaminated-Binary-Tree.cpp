#include <iostream>
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
 
class FindElements {
    unordered_set<int> visited;
public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return visited.count(target);
    }
private:
    void dfs(TreeNode* node, int currentValue) {
        if (node == nullptr) return;
        visited.insert(currentValue);
        dfs(node->left, 2 * currentValue + 1);
        dfs(node->right, 2 * currentValue + 2);
    }
};

int main() {
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(-1, new TreeNode(-1), new TreeNode(-1));
    root->right = new TreeNode(-1);

    FindElements* obj = new FindElements(root);
    cout << obj->find(1) << endl; // true
    cout << obj->find(3) << endl; // true
    cout << obj->find(5) << endl; // false
}