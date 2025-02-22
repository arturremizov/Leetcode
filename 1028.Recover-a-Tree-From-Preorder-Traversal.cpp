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
    TreeNode* recoverFromPreorder(string traversal) {
        const int n = traversal.length();
        int dashesCount = 0;
        vector<TreeNode*> stack;
        int i = 0;
        while (i < n) {
            if (traversal[i] == '-') {
                ++dashesCount;
                ++i;
            } else {
                int j = i;
                while (j < n && traversal[j] != '-') {
                    ++j;
                }
                int value = stoi(traversal.substr(i, j - i));
                TreeNode* node = new TreeNode(value);

                while (stack.size() > dashesCount) {
                    stack.pop_back();
                }

                if (!stack.empty() && stack.back()->left == nullptr) {
                    stack.back()->left = node;
                } else if (!stack.empty()) {
                    stack.back()->right = node;
                }
                stack.push_back(node);
                i = j;
                dashesCount = 0;
            }
        }
        return stack[0];
    }
};

int main() {
    Solution solution; 
    TreeNode* result = solution.recoverFromPreorder("1-2--3--4-5--6--7");
}