#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct EventComparator {
    bool operator() (const vector<string>& lhs, const vector<string>& rhs) const {
        int lhsTimestamp = stoi(lhs[1]);
        int rhsTimestamp = stoi(rhs[1]);
        if (lhsTimestamp == rhsTimestamp && lhs[0] == "OFFLINE") {
            return true;
        }
        return lhsTimestamp < rhsTimestamp;
    }
};

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> result(numberOfUsers);

        sort(events.begin(), events.end(), EventComparator());

        vector<int> nextOnlineTime(numberOfUsers);
        for (auto& event : events) {
            int timestamp = stoi(event[1]);
            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        result[i]++;
                    }
                } else if (event[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (timestamp >= nextOnlineTime[i]) {
                            result[i]++;
                        }
                    }
                } else {
                    vector<int> userIds = convertUserIds(event[2]);
                    for (int id : userIds) {
                        result[id]++;
                    }
                }
            } else {
                int userId = stoi(event[2]);
                nextOnlineTime[userId] = timestamp + 60;
            }
        }
        return result;
    }
private:
    vector<int> convertUserIds(string str) {
        vector<int> ids;
        int curNum = 0;
        for (int i = 0; i < str.size(); i++) {
            if (isdigit(str[i])) {
                curNum *= 10;
                curNum += str[i] - '0';
            }
            if (i + 1 == str.size() || str[i + 1] == ' ') {
                ids.push_back(curNum);
                curNum = 0;
            }
        }
        return ids;
    }
};

int main() {
    Solution solution; 
    vector<vector<string>> events = {
        {"MESSAGE","10","id1 id0"},
        {"OFFLINE","11","0"},
        {"MESSAGE","71","HERE"}
    };
    vector<int> result = solution.countMentions(2, events); // [2,2]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}