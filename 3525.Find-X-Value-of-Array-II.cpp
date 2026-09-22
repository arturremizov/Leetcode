#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    struct Node {
        int product = 0;
        int count[5] = {0};
    };
    const int n;
    const int k;
    vector<Node> tree;
public:
    SegmentTree(vector<int>& nums, int modK) : n(nums.size()), k(modK) {
        tree.assign(4 * n, Node());
        build(1, 0, n - 1, nums);
    }
    void update(int index, int value) {
        update(1, 0, n - 1, index, value);
    }
    int query(int start, int x) {
        Node node = query(1, 0, n - 1, start, n - 1);
        return node.count[x];
    }
private:
    void build(int i, int left, int right, vector<int>& nums) {
        if (left == right) {
            tree[i] = makeLeaf(nums[left]);
            return;
        }
        int mid = (left + right) / 2;
        build(i * 2, left, mid, nums);
        build(i * 2 + 1, mid + 1, right, nums);
        tree[i] = mergeNodes(tree[i * 2], tree[i * 2 + 1]);
    }
    void update(int i, int left, int right, int pos, int value) {
        if (left == right) {
            tree[i] = makeLeaf(value);
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid) {
            update(i * 2, left, mid, pos, value);
        } else {
            update(i * 2 + 1, mid + 1, right, pos, value);
        }
        tree[i] = mergeNodes(tree[i * 2], tree[i * 2 + 1]);
    }
    Node mergeNodes(const Node &left, const Node &right) {
        Node node;
        node.product = (left.product * right.product) % k;
        for (int i = 0; i < k; ++i) {
            node.count[i] = left.count[i];
        }
        for (int reminder = 0; reminder < k; ++reminder) {
            if (right.count[reminder] == 0) continue;
            int newReminder = (left.product * reminder) % k;
            node.count[newReminder] += right.count[reminder]; 
        }
        return node;
    }
    Node query(int i, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > queryRight) return emptyNode();
        if (queryLeft == left && queryRight == right) return tree[i];
        int mid = (left + right) / 2;
        Node leftPart = query(i * 2, left, mid, queryLeft, min(mid, queryRight));
        Node rightPart = query(i * 2 + 1, mid + 1, right, max(mid + 1, queryLeft), queryRight);
        return mergeNodes(leftPart, rightPart);
    }
    Node makeLeaf(int value) {
        Node node;
        int remider = value % k;
        node.product = remider;
        node.count[remider]++;
        return node;
    }
    Node emptyNode() const {
        Node node;
        node.product = 1;
        return node;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree segmentTree(nums, k);
        vector<int> result;
        for (auto& query : queries) {
            int index = query[0], value = query[1], start = query[2], x = query[3];
            segmentTree.update(index, value);
            result.push_back(segmentTree.query(start, x));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3,4,5};
    vector<vector<int>> queries = {{2,2,0,2},{3,3,3,0},{0,1,0,1}};
    vector<int> result = solution.resultArray(nums, 3, queries); // [2,2,2]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}