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
        ListNode *prev = head, *current = head->next, *next = current->next;
        int min_dist = INT_MAX, max_dist = -1;

        int prev_crit_idx = 0;
        int first_crit_idx = 0;
        int i = 1; // index of current

        while (next) {
            if (isCritical(prev, current, next)) {
                if (first_crit_idx) {
                    max_dist = i - first_crit_idx;
                    min_dist = min(min_dist, i - prev_crit_idx);
                } else {
                    first_crit_idx = i;
                }
                prev_crit_idx = i;
            }
            prev = current;
            current = next;
            next = next->next;
            ++i;
        }

        if (min_dist == INT_MAX) {
            min_dist = -1;
        }
        return {min_dist, max_dist};
    }
private:
    bool isCritical(ListNode *prev, ListNode *current, ListNode *next) {
        return (prev->val > current->val && current->val < next->val) || 
               (prev->val < current->val && current->val > next->val);
    } 
};

int main() 
{
    Solution solution; 
    ListNode *root = new ListNode(5);
    root->next = new ListNode(3);
    root->next->next = new ListNode(1);
    root->next->next->next = new ListNode(2);
    root->next->next->next->next = new ListNode(5);
    root->next->next->next->next->next = new ListNode(1);
    root->next->next->next->next->next->next = new ListNode(2);
    vector<int> result = solution.nodesBetweenCriticalPoints(root); // [1,3]
    for (int num : result) {
        cout << num << ",";
    }
}