#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
    vector<int> stack;
    int index;
public:
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        index = -1;
    }
    
    void push(int x) {
        if (stack.size() - 1 == index) return;
        stack[++index] = x;
    }
    
    int pop() {
        if (index < 0) return -1;
        return stack[index--];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, (int)stack.size()); ++i) {
            stack[i] += val;
        }
    }
};

int main() {
    CustomStack* stk = new CustomStack(3);
    stk->push(1);     
    stk->push(2); 
    cout << stk->pop() << endl; // 2
    stk->push(2);  
    stk->push(3);     
    stk->push(4);   
    stk->increment(5, 100);  
    stk->increment(2, 100);   
    cout << stk->pop() << endl; // 103
    cout << stk->pop() << endl; // 202
    cout << stk->pop() << endl; // 201
    cout << stk->pop() << endl; // -1
}