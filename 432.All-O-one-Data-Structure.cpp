#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class AllOne {
    class Node {
    public:
        int count; 
        unordered_set<string> keys; 
        Node* next; 
        Node* prev;
        Node(int c, Node* p = nullptr, Node* n = nullptr) : count(c), prev(p), next(n) {}
    };
    Node* head; 
    Node* tail;
    unordered_map<string, Node*> map; 
public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail; 
        tail->prev = head;
    }

    void inc(string key) {
        if (!map.count(key)) {
            Node* node = head->next;
            if (node == tail || node->count > 1) {
                Node* newNode = new Node(1, head, head->next);
                head->next->prev = newNode;
                head->next = newNode;

                newNode->keys.insert(key);
                map[key] = newNode;
            } else {
                node->keys.insert(key);
                map[key] = node;
            }
            
        } else {
            Node* currentNode = map[key];
            int currentCount = currentNode->count;
            currentNode->keys.erase(key);

            Node* nextNode = currentNode->next;
            if (nextNode == tail || nextNode->count != currentCount + 1) {
                Node* newNode = new Node(currentCount + 1, currentNode, nextNode); 
                currentNode->next = newNode;
                nextNode->prev = newNode;

                newNode->keys.insert(key);
                map[key] = newNode;
            } else {
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }

            if (currentNode->keys.empty()) {
                removeNode(currentNode);
            }
        }
    }

    void dec(string key) {
        if (!map.count(key)) return;  
        Node *currentNode = map[key];
        int currentCount = currentNode->count;
        currentNode->keys.erase(key);

        if (currentCount == 1) {
            map.erase(key);
        } else {
            Node* prevNode = currentNode->prev;
            if (prevNode == head || prevNode->count != currentCount - 1) {
                Node* newNode = new Node(currentCount - 1, prevNode, currentNode); 
                prevNode->next = newNode;
                currentNode->prev = newNode;

                newNode->keys.insert(key);
                map[key] = newNode;
            } else {
                prevNode->keys.insert(key);
                map[key] = prevNode;
            }
        }

        if (currentNode->keys.empty()) {
            removeNode(currentNode);
        }
    }

    string getMaxKey() {
        return tail->prev == head ? "" : *tail->prev->keys.begin();
    }

    string getMinKey() {
        return head->next == tail ? "" : *head->next->keys.begin();
    }
private:
    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
};

int main() {
    AllOne* allOne = new AllOne();
    allOne->inc("hello");
    allOne->inc("goodbye");
    allOne->inc("hello");
    allOne->inc("hello");
    cout << allOne->getMaxKey() << endl; // hello
    cout << allOne->getMinKey() << endl; // goodbye
}