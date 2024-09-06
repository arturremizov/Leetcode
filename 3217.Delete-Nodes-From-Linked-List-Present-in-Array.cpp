#include <iostream>
#include <vector>
#include <unordered_set>

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        while (prev->next) {
            if (numsSet.count(prev->next->val)) {
                prev->next = prev->next->next;
            } else {
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    Solution solution; 

    vector<int> nums = {1,2,3};

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *result = solution.modifiedList(nums,head); //  [4,5]
}