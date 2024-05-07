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
    ListNode* removeNodes(ListNode* head) {
        ListNode* reversedHead = reverse(head);
        ListNode* current = reversedHead;
        int currentMax = current->val;
        while (current->next) {
            if (current->next->val < currentMax) {
                current->next = current->next->next;
            } else {
                currentMax = current->next->val;
                current = current->next;
            }
        }
        return reverse(reversedHead);
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *current = head;
        while (current) {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;          
        }
        return prev;
    }
};

int main() 
{
    ListNode *head = new ListNode(5, new ListNode(2, new ListNode(13, new ListNode(3, new ListNode(8)))));
;
    Solution solution; 
    ListNode *result = solution.removeNodes(head);
}