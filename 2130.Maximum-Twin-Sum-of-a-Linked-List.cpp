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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* nextSlow = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextSlow;
        }
        int result = 0;
        while (slow) {
            result = max(result, slow->val + prev->val);
            slow = slow->next;
            prev = prev->next;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    ListNode *head = new ListNode(5, new ListNode(4, new ListNode(2, new ListNode(1))));
    cout << solution.pairSum(head) << endl; // 6
}