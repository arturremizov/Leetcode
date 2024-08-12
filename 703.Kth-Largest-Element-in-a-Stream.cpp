#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kLargest;
public:
    KthLargest(int k, vector<int>& nums) {
        kLargest = k;
        for (int num : nums) {
            minHeap.push(num);
        }
        while (minHeap.size() > kLargest) {
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > kLargest) {
            minHeap.pop();
        }
        return minHeap.top();
    }

};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(3, nums);
    cout << obj->add(3) << endl; // 4
    cout << obj->add(5) << endl; // 5
    cout << obj->add(10) << endl; // 5
    cout << obj->add(9) << endl; // 8
    cout << obj->add(4) << endl; // 8
}