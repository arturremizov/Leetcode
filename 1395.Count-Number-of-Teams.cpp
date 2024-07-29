#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int result = 0;
        const int n = rating.size();
        for (int mid = 1; mid < n - 1; mid++) {
            int leftSmaller = 0, rightLarger = 0;
            for (int i = 0; i < mid; i++) {
                if (rating[i] < rating[mid]) {
                    ++leftSmaller;
                }
            }
            for (int i = mid + 1; i < n; i++) {
                if (rating[mid] < rating[i]) {
                    ++rightLarger;
                }
            }
            result += leftSmaller * rightLarger;

            int leftLarger = mid - leftSmaller;
            int rightSmaller = n - 1 - mid - rightLarger;
            result += leftLarger * rightSmaller; 
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> rating = {2,5,3,4,1};
    cout << solution.numTeams(rating) << endl; // 3
}