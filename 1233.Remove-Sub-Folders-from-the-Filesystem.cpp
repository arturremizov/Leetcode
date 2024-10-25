#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        for (string f : folder) {
            if (result.empty() || f.find(result.back() + "/") != 0) {
                result.push_back(f);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    vector<string> result = solution.removeSubfolders(folder); // ["/a","/c/d","/c/f"]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}