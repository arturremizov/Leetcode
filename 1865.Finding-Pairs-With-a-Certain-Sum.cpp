#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int, int> numCount;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            numCount[num]++;
        }
    }
    
    void add(int index, int val) {
        numCount[nums2[index]]--;
        nums2[index] += val;
        numCount[nums2[index]]++;
    }
    
    int count(int tot) {
        int result = 0;
        for (int num : nums1) {
            if (numCount.count(tot - num)) {
                result += numCount[tot - num];
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2 = {1, 4, 5, 2, 5, 4};
    FindSumPairs* obj = new FindSumPairs(nums1, nums2);
    cout << obj->count(7) << endl; // 8
    obj->add(3, 2);
    cout << obj->count(8) << endl; // 2
    cout << obj->count(4) << endl; // 1
    obj->add(0, 1);
    obj->add(1, 1);
    cout << obj->count(7) << endl; // 11
}