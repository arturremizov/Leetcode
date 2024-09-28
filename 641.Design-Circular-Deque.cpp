#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
    vector<int> queue;
    int front;
    int back;
    int k;
    int size;
public:
    MyCircularDeque(int k) {
        queue = vector<int>(k);
        this->k = k;
        front = 0;
        back = k - 1;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + k) % k;
        queue[front] = value;
        ++size;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        back = (back + 1) % k;
        queue[back] = value;
        ++size;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % k;
        --size;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        back = (back - 1 + k) % k;
        --size;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return queue[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return queue[back];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};


int main() {
    MyCircularDeque* obj = new MyCircularDeque(3);
    cout << obj->insertLast(1) << endl; // true
    cout << obj->insertLast(2) << endl; // true
    cout << obj->insertFront(3) << endl; // true
    cout << obj->insertFront(4) << endl; // false
    cout << obj->getRear() << endl; // 2
    cout << obj->isFull() << endl; // true
    cout << obj->deleteLast() << endl; // true
    cout << obj->insertFront(4) << endl; // true
    cout << obj->getFront() << endl; // true
}