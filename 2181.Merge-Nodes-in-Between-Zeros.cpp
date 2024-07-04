#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current = head;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (current->next) {
            ListNode* node = new ListNode();
            while (current->next->val != 0) {
                node->val += current->next->val;
                current = current->next;
            }
            tail->next = node;
            tail = node;
            current = current->next;
        }
        return dummy->next;
    }
};

int main() 
{
    Solution solution; 
    ListNode *root = new ListNode(0);
    root->next = new ListNode(1);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(0);
    root->next->next->next->next->next = new ListNode(2);
    root->next->next->next->next->next->next = new ListNode(2);
    root->next->next->next->next->next->next->next = new ListNode(0);
    ListNode *result = solution.mergeNodes(root); // [1,3,4]

}