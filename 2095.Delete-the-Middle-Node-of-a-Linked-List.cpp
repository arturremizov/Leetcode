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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;
        ListNode *slow = head, *fast = head;
        ListNode *prev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};

int main() {
    Solution solution; 
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    cout << solution.deleteMiddle(head) << endl; // [1,2,4]
}