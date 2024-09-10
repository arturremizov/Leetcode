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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        while (current->next) {
            int num1 = current->val;
            int num2 = current->next->val;
            current->next = new ListNode(gcd(num1, num2), current->next);
            current = current->next->next;
        }
        return head;
    }
private:
    int gcd(int a, int b) {
        while (b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    Solution solution; 

    ListNode *head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);

    ListNode* result = solution.insertGreatestCommonDivisors(head); // [18,6,6,2,10,1,3]
}