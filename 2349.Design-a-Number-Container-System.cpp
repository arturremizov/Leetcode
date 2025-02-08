#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class NumberContainers {
    unordered_map<int,int> indexToNumber;
    unordered_map<int,set<int>> numberToIndices;
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        if (numberToIndices.count(number)) {
            return *numberToIndices[number].begin();
        }
        return -1;
    }
};

int main() {
    NumberContainers* obj = new NumberContainers();
    cout << obj->find(10) << endl; // -1
    obj->change(2,10);
    obj->change(1,10);
    obj->change(3,10);
    obj->change(5,10);
    cout << obj->find(10) << endl; // 1
    obj->change(1,20);
    cout << obj->find(10) << endl; // 2
}