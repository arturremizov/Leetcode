#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    int minimumOperations(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> levelVector;
            while (levelSize--) {
                TreeNode* node = queue.front();
                queue.pop();
                levelVector.push_back(node->val);
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            result += countSwaps(levelVector);
        }
        return result;
    }
private:
    int countSwaps(vector<int>& nums) {
        int swaps = 0;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        unordered_map<int, int> indexMap;
        for (int i = 0; i < nums.size(); ++i) {
            indexMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != sortedNums[i]) {
                ++swaps;
                int j = indexMap[sortedNums[i]];
                swap(nums[i], nums[j]);
                indexMap[nums[i]] = i;
                indexMap[nums[j]] = j;
            }
        }
        return swaps;
    }
};

int main() {
    Solution solution; 
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4, new TreeNode(7), new TreeNode(6));
    root->right = new TreeNode(3, new TreeNode(8), new TreeNode(5));
    root->right->left->left = new TreeNode(9);
    root->right->right->left = new TreeNode(10);
    cout << solution.minimumOperations(root) << endl; // 3
}