#include <iostream>

using namespace std;

class MyCalendar {
    class Tree {
        int start;
        int end;
        Tree* left;
        Tree* right;
    public:
        Tree(int start, int end) {
            this->start = start;
            this->end = end;
            this->left = nullptr;
            this->right = nullptr;
        }
    
        bool insert(int start, int end) {
            Tree* current = this;
            while (true) {
                if (start >= current->end) {
                    if (!current->right) {
                        current->right = new Tree(start, end);
                        return true;
                    }
                    current = current->right;
                } else if (end <= current->start) {
                    if (!current->left) {
                        current->left = new Tree(start, end);
                        return true;
                    }
                    current = current->left;
                } else {
                    return false;
                }
            }
            
        }
    };
    Tree* root;
public:
    MyCalendar() {
        this->root = nullptr;
    }
    
    bool book(int start, int end) {
        if (root == nullptr) {
            root = new Tree(start, end);
            return true;
        } 
        return root->insert(start, end);
    }
};

int main() {
    MyCalendar* obj = new MyCalendar();
    cout << obj->book(10, 20) << endl; // true
    cout << obj->book(15, 25) << endl; // false
    cout << obj->book(20, 30) << endl; // true
}