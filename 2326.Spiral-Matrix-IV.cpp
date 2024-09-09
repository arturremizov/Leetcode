#include <iostream>
#include <vector>

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left = 0, right = n;
        int top = 0, bottom = m;
        vector<vector<int>> result(m, vector<int>(n, -1));

        while (head) {
            // left to right
            for (int i = left; i < right; i++) {
                if (head == NULL) return result;
                result[top][i] = head->val;
                head = head->next;
            }
            top += 1;

            // top to bottom
            for (int i = top; i < bottom; i++) {
                if (head == NULL) return result;
                result[i][right - 1] = head->val;
                head = head->next;
            }
            right -= 1;

            // right to left
            for (int i = right - 1; i >= left; i--) {
                if (head == NULL) return result;
                result[bottom - 1][i] = head->val;
                head = head->next;
            }
            bottom -= 1;

            // bottom to top
            for (int i = bottom - 1; i >= top; i--) {
                if (head == NULL) return result;
                result[i][left] = head->val;
                head = head->next;
            }
            left += 1;
        }
        return result;
    }
};

int main() {
    Solution solution; 

    ListNode *head = new ListNode(3,new ListNode(0,new ListNode(2,new ListNode(6,new ListNode(8,new ListNode(1,new ListNode(7,new ListNode(9,new ListNode(4,new ListNode(2,new ListNode(5,new ListNode(5,new ListNode(0)))))))))))));

    vector<vector<int>> result = solution.spiralMatrix(3,5,head);
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}