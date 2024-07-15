#include <iostream>
#include <vector>
#include <unordered_map>
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        for (const vector<int>& description : descriptions) {
            int parrent = description[0], child = description[1], isLeft = description[2];

            children.insert(child);
            if (!nodes.count(parrent)) {
                nodes[parrent] = new TreeNode(parrent);
            }
            if (!nodes.count(child)) {
                nodes[child] = new TreeNode(child);
            }
            if (isLeft) {
                nodes[parrent]->left = nodes[child];
            } else {
                nodes[parrent]->right = nodes[child];
            }
        }
        for (const vector<int>& description : descriptions) {
            int parrent = description[0];
            if (!children.count(parrent)) {
                return nodes[parrent];
            }
        }
        return NULL;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> descriptions = {{20,15,1}, {20,17,0}, {50,20,1}, {50,80,0}, {80,19,1}};
    TreeNode* result = solution.createBinaryTree(descriptions);
}