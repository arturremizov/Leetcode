#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    template<class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        const int n = arr.size();
        min_heap<pair<double, pair<int,int>>> minHeap;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                minHeap.push({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }
        for (int i = 0; i < k - 1; ++i) {
            minHeap.pop();
        }
        auto result = minHeap.top().second;
        return {result.first, result.second};
    }
};


int main() 
{
    Solution solution; 
    vector<int> arr = {1,2,3,5};
    vector<int> result = solution.kthSmallestPrimeFraction(arr, 3); // [2,5]
    for (int num : result) {
        cout << num << ",";
    }
}