#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    struct Node {
        int length;
        char leftChar;
        char rightChar;
        int leftCharsLength;
        int rightCharsLength;
        int maxCharsLength;
    };
    string s;
    const int n;
    vector<Node> tree;
public:
    SegmentTree(string str) : s(str), n(s.length()) {
        tree.assign(4 * n, Node{}); 
        build(1, 0, n - 1);
    }
    void update(int pos, char c) {
        update(1, 0, n - 1, pos, c);
    }
    int getMaxCharsLength() {
        return tree[1].maxCharsLength;
    }
private:
    void build(int i, int left, int right) {
        if (left == right) {
            tree[i] = makeLeaf(s[left]);
            return;
        }
        int mid = (left + right) / 2;
        build(i * 2, left, mid);
        build(i * 2 + 1, mid + 1, right);
        tree[i] = mergeNodes(tree[i * 2], tree[i * 2 + 1]);
    }
    Node makeLeaf(char c) {
        return {1,c,c,1,1,1};
    }
    Node mergeNodes(const Node& left, const Node& right) {
        Node node;
        node.length = left.length + right.length;
        node.leftChar = left.leftChar;
        node.rightChar = right.rightChar;
        if (left.leftCharsLength == left.length && left.rightChar == right.leftChar) {
            node.leftCharsLength = left.length + right.leftCharsLength;
        } else {
            node.leftCharsLength = left.leftCharsLength;
        }
        if (right.rightCharsLength == right.length && right.leftChar == left.rightChar) {
            node.rightCharsLength = right.length + left.rightCharsLength;
        } else {
            node.rightCharsLength = right.rightCharsLength;
        }
        node.maxCharsLength = max(left.maxCharsLength, right.maxCharsLength);
        if (left.rightChar == right.leftChar) {
            node.maxCharsLength = max(node.maxCharsLength, left.rightCharsLength + right.leftCharsLength);
        }
        return node;
    }
    void update(int i, int left, int right, int pos, char c) {
        if (left == right) {
            s[left] = c;
            tree[i] = makeLeaf(c);
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid) {
            update(i * 2, left, mid, pos, c);
        } else {
            update(i * 2 + 1, mid + 1, right, pos, c);
        }
        tree[i] = mergeNodes(tree[i * 2], tree[i * 2 + 1]);
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        const int k = queryCharacters.length();
        SegmentTree segmentTree(s);
        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            char c = queryCharacters[i];
            int index = queryIndices[i];
            segmentTree.update(index, c);
            result[i] = segmentTree.getMaxCharsLength();
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> queryIndices = {1,3,3};
    vector<int> result = solution.longestRepeating("babacc", "bcb", queryIndices); //[3,3,4]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}