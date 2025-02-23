#include <iostream>
#include <vector>
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const int n = preorder.size();
        unordered_map<int, int> postValueToIndex;
        for (int i = 0; i < n; ++i) {
            postValueToIndex[postorder[i]] = i;
        }
        return buildTree(0, n - 1, 0, n - 1, preorder, postorder, postValueToIndex);
    }
private:
    TreeNode* buildTree(int i1, int i2, int j1, int j2, 
                        vector<int>& preorder, vector<int>& postorder,
                        unordered_map<int, int>& postValueToIndex) {
                            
        if (i1 > i2 || j1 > j2) return nullptr;

        TreeNode* root = new TreeNode(preorder[i1]);
        if (i1 != i2) {
            int leftValue = preorder[i1 + 1];
            int mid = postValueToIndex[leftValue];
            int leftSize = mid - j1 + 1;
            root->left = buildTree(i1+1, i1+leftSize, j1, mid,  preorder, postorder, postValueToIndex);
            root->right = buildTree(i1+leftSize+1, i2, mid+1, i2-1,  preorder, postorder, postValueToIndex);
        }
        return root;
    }
};

int main() {
    Solution solution; 
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    TreeNode* result = solution.constructFromPrePost(preorder,postorder);
}