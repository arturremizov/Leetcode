#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Packet {
    int source;
    int destination;
    int timestamp;

    bool operator==(const Packet& other) const {
        return source == other.source &&
               destination == other.destination &&
               timestamp == other.timestamp;
    }
};

struct PacketHash {
    size_t operator()(const Packet& p) const {
        size_t h1 = hash<int>()(p.source);
        size_t h2 = hash<int>()(p.destination);
        size_t h3 = hash<int>()(p.timestamp);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

class Router {
    int memoryLimit;
    queue<Packet> packetsQueue;
    unordered_set<Packet, PacketHash> packetsSet;
    unordered_map<int, deque<int>> destToTimestamp;
public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet packet = {source, destination, timestamp};
        if (packetsSet.count(packet)) return false;
        if (packetsQueue.size() == memoryLimit) {
            removeTopPacket();
        }
        packetsSet.insert(packet);
        packetsQueue.push(packet);
        destToTimestamp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packetsQueue.empty()) return {};
        Packet packet = removeTopPacket();
        return {packet.source, packet.destination, packet.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!destToTimestamp.count(destination)) return 0;
        deque<int>& timestamps = destToTimestamp[destination];
        auto left = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto right = upper_bound(timestamps.begin(), timestamps.end(), endTime);
        return right - left;
    }
private:
    Packet removeTopPacket() {
        Packet packet = packetsQueue.front();
        packetsQueue.pop();
        packetsSet.erase(packet);
        destToTimestamp[packet.destination].pop_front();
        return packet;
    }
};

int main() {
    Router* router = new Router(3);
    cout << router->addPacket(1,4,90) << endl; // true
    cout << router->addPacket(2,5,90) << endl; // true
    cout << router->addPacket(1,4,90) << endl; // false
    cout << router->addPacket(3,5,95) << endl; // true
    cout << router->addPacket(4,5,105) << endl; // true
    vector<int> result = router->forwardPacket();
    cout << "[" << result[0] << "," << result[1] << "," << result[2] << "]" << endl; // [2, 5, 90]
    cout << router->addPacket(5,2,110) << endl; // true
    cout << router->addPacket(5,100,100) << endl; // 1
} 