#include <iostream>
#include <vector>

using namespace std;

class MyCalendarTwo {
    vector<pair<int, int>> nonOverlapping;
    vector<pair<int, int>> overlapping;
public:
    MyCalendarTwo() { }
    
    bool book(int start, int end) {
        for (auto [s, e] : overlapping) {
            if (!(end <= s || e <= start)) {
                return false;
            }
        }

        for (auto [s, e] : nonOverlapping) {
            if (!(end <= s || e <= start)) {
                overlapping.push_back({max(s, start), min(e, end)});
            }
        }
        nonOverlapping.push_back({start, end});
        return true;
    }
};

int main() {
    MyCalendarTwo* obj = new MyCalendarTwo();
    cout << obj->book(10, 20) << endl; // true
    cout << obj->book(50, 60) << endl; // true
    cout << obj->book(10, 40) << endl; // true
    cout << obj->book(5, 15) << endl; // false
    cout << obj->book(5, 10) << endl; // true
    cout << obj->book(25, 55) << endl; // true
}