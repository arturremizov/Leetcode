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
    ListNode* doubleIt(ListNode* head) {
        if (head->val > 4) {
            head = new ListNode(0, head);
        }
        ListNode *current = head;
        while (current) {
            current->val = (current->val * 2) % 10;
            if (current->next != NULL && current->next->val > 4) {
                current->val++;
            }
            current = current->next;
        }
        return head;
    }
};

int main() 
{
    Solution solution; 
    ListNode *head = new ListNode(1, new ListNode(8, new ListNode(9)));
    ListNode *result = solution.doubleIt(head->next);
}