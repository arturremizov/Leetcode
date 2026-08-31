#include <iostream>
#include <vector>
#include <climits>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX, maxDistance = -1;
        int firstPoint = -1, prevPoint = -1;
        ListNode *prev = head, *cur = head->next;
        int i = 1;
        while (cur->next) {
            if (isCriticalPoint(prev, cur, cur->next)) {
                if (firstPoint == -1) {
                    firstPoint = i;
                } else {
                    minDistance = min(minDistance, i - prevPoint);
                    maxDistance = i - firstPoint;
                }
                prevPoint = i;
            }
            prev = cur;
            cur = cur->next;
            ++i;
        }
        if (minDistance == INT_MAX) {
            minDistance = -1;
        }
        return {minDistance, maxDistance};
    }
private:
    bool isCriticalPoint(ListNode* prev, ListNode* cur, ListNode* next) {
        return (prev->val > cur->val && cur->val < next->val) ||
               (prev->val < cur->val && cur->val > next->val);
    }
};

int main() {
    Solution solution; 
    ListNode *root = new ListNode(5);
    root->next = new ListNode(3);
    root->next->next = new ListNode(1);
    root->next->next->next = new ListNode(2);
    root->next->next->next->next = new ListNode(5);
    root->next->next->next->next->next = new ListNode(1);
    root->next->next->next->next->next->next = new ListNode(2);
    vector<int> result = solution.nodesBetweenCriticalPoints(root); // [1,3]
    cout << "[" << result[0] << "," << result[1] << "]\n";
}