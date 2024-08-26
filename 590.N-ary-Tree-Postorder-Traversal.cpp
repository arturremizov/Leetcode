#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        stack<Node*> stack;
        if (root != NULL) {
            stack.push(root);
        }
        while (!stack.empty()) {
            auto node = stack.top();
            stack.pop();

            result.push_back(node->val);
            for (auto child : node->children) {
                stack.push(child);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution; 

    Node *root = new Node(1);
    root->children = {
        new Node(3, {new Node(5), new Node(6)}),
        new Node(2),
        new Node(4)
    };

    vector<int> result = solution.postorder(root); // [5,6,3,2,4,1]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}