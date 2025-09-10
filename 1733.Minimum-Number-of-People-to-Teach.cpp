#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        const int usersCount = languages.size();
        vector<unordered_set<int>> userToLanguage(usersCount);
        for (int i = 0; i < usersCount; ++i) {
            for (int lang : languages[i]) {
                userToLanguage[i].insert(lang);
            }
        }

        unordered_set<int> problematicUsers;
        for (auto& friends : friendships) {
            int user1 = friends[0] - 1, user2 = friends[1] - 1;
            bool canTalk = false;
            for (int language : userToLanguage[user1]) {
                if (userToLanguage[user2].count(language)) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) {
                problematicUsers.insert(user1);
                problematicUsers.insert(user2);
            }
        }

        int result = usersCount;
        for (int lang = 1; lang <= n; ++lang) {
            int needsToTeach = 0;
            for (int user : problematicUsers) {
                if (!userToLanguage[user].count(lang)) {
                    ++needsToTeach;
                }
            }
            result = min(result, needsToTeach);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> languages = {{2}, {1,3}, {1,2}, {3}};
    vector<vector<int>> friendships = {{1,4}, {1,2}, {3,4}, {2,3}};
    cout << solution.minimumTeachings(3, languages, friendships) << endl; // 2
}
