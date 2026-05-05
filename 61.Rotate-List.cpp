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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        int length = 1;
        ListNode *tail = head;
        while (tail->next) {
            ++length;
            tail = tail->next;
        }
       
        k = k % length;
        if (k == 0) return head;

        ListNode *cur = head;
        for (int i = 0; i < length - k - 1; ++i) {
            cur = cur->next;
        }
        ListNode *newHead = cur->next;
        cur->next = nullptr;
        tail->next = head;
        return newHead;        
    }
};

int main() {
    Solution solution; 
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode *result = solution.rotateRight(head, 2); // [4,5,1,2,3]
}