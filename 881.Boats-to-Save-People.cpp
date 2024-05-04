#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int result = 0;
        int left = 0, right = people.size() - 1;
        while (left <= right) {
            int remain = limit - people[right];
            --right;
            ++result;
            if (left <= right && remain >= people[left]) {
                ++left;
            } 
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> people = {1,2};
    cout << solution.numRescueBoats(people, 3) << endl; // 1
    vector<int> people2 = {3,2,2,1};
    cout << solution.numRescueBoats(people2, 3) << endl; // 3
    vector<int> people3 = {3,5,3,4};
    cout << solution.numRescueBoats(people3, 5) << endl; // 4
}