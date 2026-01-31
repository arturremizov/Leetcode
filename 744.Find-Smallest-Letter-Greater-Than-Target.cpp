#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size() - 1;
        char result = letters[0];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (letters[mid] > target) {
                result = letters[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<char> letters = {'c','f','j'};
    cout << solution.nextGreatestLetter(letters, 'a') << endl; // "c"
}