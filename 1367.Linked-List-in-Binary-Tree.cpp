#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (helper(head, root)) return true;
        if (root == NULL) return false;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
private:
    bool helper(ListNode* listNode, TreeNode* treeNode) {
        if (listNode == NULL) return true;
        if (treeNode == NULL || listNode->val != treeNode->val) return false;
        return helper(listNode->next, treeNode->left) || helper(listNode->next, treeNode->right);
    }
};

int main() {
    Solution solution; 

    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(6);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4, NULL, new TreeNode(2, new TreeNode(1), NULL));
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8, new TreeNode(1), new TreeNode(3));

    cout << solution.isSubPath(head, root) << endl; // true
}