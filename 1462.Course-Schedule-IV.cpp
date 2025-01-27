#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjacencyList;
        for (auto prerequisite : prerequisites) {
            adjacencyList[prerequisite[1]].push_back(prerequisite[0]);
        }

        unordered_map<int, unordered_set<int>> prerequisitesMap;
        for (int course = 0; course < numCourses; ++course) {
            dfs(course,adjacencyList,prerequisitesMap);
        }

        vector<bool> result;
        for (auto query : queries) {
            int u = query[0], v = query[1];
            bool answer = prerequisitesMap[v].count(u) == 0 ? false : true;
            result.push_back(answer);
        }   
        return result;
    }
private:
    unordered_set<int> dfs(int course, 
                           unordered_map<int, vector<int>>& adjacencyList,
                           unordered_map<int, unordered_set<int>>& prerequisitesMap) {

        if (!prerequisitesMap.count(course)) {
            for (int prerequisite : adjacencyList[course]) {
                auto resultSet = dfs(prerequisite,adjacencyList,prerequisitesMap);
                prerequisitesMap[course].merge(resultSet);
            }
            prerequisitesMap[course].insert(course);
        }
        return prerequisitesMap[course];
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> prerequisites = {{1,0}};
    vector<vector<int>> queries = {{0,1}, {1,0}};
    vector<bool> result = solution.checkIfPrerequisite(2,prerequisites,queries); //[false,true]
    for (int i = 0; i < result.size(); ++i) { 
        cout << ((result[i] == true) ? "true" : "false");
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}