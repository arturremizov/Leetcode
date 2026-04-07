#include <iostream>
#include <vector>
using namespace std;

class Robot {
    int width = 0, height = 0;
    int circle = 0;
    int steps = 0;
    bool isInitialPosition = true;
public:
    Robot(int width, int height) { 
        this->width = width - 1;
        this->height = height - 1;
        circle = (this->width + this->height) * 2;
    }
    
    void step(int num) {
        isInitialPosition = false;
        steps = (steps + num) % circle;
    }
    
    vector<int> getPos() {
        if (steps <= width) {
            return {steps, 0};
        }
        if (steps <= width + height) {
            return {width, steps - width};
        }
        if (steps <= width * 2 + height) {
            return {(width * 2 + height) - steps, height};
        }
        return {0, circle - steps};
    }
    
    string getDir() {
        if (isInitialPosition) return "East";
        if (steps == 0) return "South";
        if (steps <= width) return "East";
        if (steps <= width + height) return "North";
        if (steps <= width * 2 + height) return "West";
        return "South";
    }
};

int main() {
    Robot* robot = new Robot(6, 3);
    robot->step(2);
    robot->step(2); 

    auto pos = robot->getPos();
    cout << "[" << pos[0] << "," << pos[1] << "]" << endl; // [4, 0]

    cout << robot->getDir() << endl; // "East"

    robot->step(2); 
    robot->step(1);
    robot->step(4);

    auto pos2 = robot->getPos();
    cout << "[" << pos2[0] << "," << pos2[1] << "]" << endl; // [1, 2]

    cout << robot->getDir() << endl; // "West"
}