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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head != nullptr) {
            result = result << 1;
            result |= head->val;
            head = head->next;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    ListNode *head = new ListNode(1, new ListNode(0, new ListNode(1)));
    cout << solution.getDecimalValue(head) << endl; // 5
}