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
    int maxHeightAfterRemoval[100001];
    int currentMaxHeight = 0;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverseLeftToRight(root, 0);
        currentMaxHeight = 0;
        traverseRightToLeft(root, 0);

        int queryCount = queries.size();
        vector<int> queryResults(queryCount);
        for (int i = 0; i < queryCount; i++) {
            queryResults[i] = maxHeightAfterRemoval[queries[i]];
        }

        return queryResults;
    }

private:
    void traverseLeftToRight(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        maxHeightAfterRemoval[node->val] = currentMaxHeight;

        currentMaxHeight = max(currentMaxHeight, currentHeight);

        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }
    
    void traverseRightToLeft(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        maxHeightAfterRemoval[node->val] =
            max(maxHeightAfterRemoval[node->val], currentMaxHeight);

        currentMaxHeight = max(currentHeight, currentMaxHeight);

        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};

int main() {
    Solution solution; 
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(2, new TreeNode(4), new TreeNode(6));
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(9, new TreeNode(3), new TreeNode(7));

    vector<int> queries = {3,2,4,8};
    vector<int> result = solution.treeQueries(root, queries); // [3,2,3,2]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}