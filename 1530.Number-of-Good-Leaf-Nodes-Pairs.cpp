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
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return pairs;
    }
private:
    int pairs = 0;
    vector<int> dfs(TreeNode* node, int distance) {
        if (!node) return {};
        if (!node->left && !node->right) return {1};
        auto left_dist = dfs(node->left, distance);
        auto right_dist = dfs(node->right, distance);
        for (int dist1 : left_dist) {
            for (int dist2 : right_dist) {
                if (dist1 + dist2 <= distance) ++pairs;
            }
        }

        vector<int> all_dist = left_dist;
        all_dist.insert(all_dist.end(), right_dist.begin(), right_dist.end());
        for (int i = 0; i < all_dist.size(); ++i) {
            all_dist[i]++;
        }
        return all_dist;
    }
};

int main() 
{
    Solution solution; 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
    cout << solution.countPairs(root, 3) << "\n"; // 2
}