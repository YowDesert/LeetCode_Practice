#include <bits/stdc++.h>
using namespace std;

struct Packet
{
    int source;
    int destination;
    int timestamp;
};

class Router
{
private:
    int memoryLimit;
    deque<Packet> buffer;            // FIFO 儲存封包
    unordered_set<string> packetSet; // 用來檢查重複 (source|destination|timestamp)
    unordered_map<int, multiset<int>> destinationMap;
    // key = destination, value = timestamps (排序好的，方便 getCount)

    // 產生封包唯一 key
    string makeKey(int source, int destination, int timestamp)
    {
        return to_string(source) + "|" + to_string(destination) + "|" + to_string(timestamp);
    }

public:
    Router(int limit)
    {
        memoryLimit = limit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        // TODO:
        // 1. 檢查是否重複 (packetSet)
        // 2. 如果重複 return false
        // 3. 如果 buffer 滿了 -> 移除最舊的封包 (pop_front)，更新 packetSet & destinationMap
        // 4. 插入新封包到 buffer、packetSet、destinationMap
        // 5. return true
        return false; // 暫時回傳 false
    }

    vector<int> forwardPacket()
    {
        // TODO:
        // 1. 如果 buffer 空，回傳 {}
        // 2. 取出 buffer.front()，從 buffer 移除
        // 3. 從 packetSet 和 destinationMap 移除對應紀錄
        // 4. 回傳 {source, destination, timestamp}
        return {}; // 暫時回傳空 vector
    }

    int getCount(int destination, int startTime, int endTime)
    {
        // TODO:
        // 使用 destinationMap[destination]，在 multiset 裡找 >= startTime 且 <= endTime 的數量
        // 可以用 lower_bound() / upper_bound() 來計算範圍
        return 0; // 暫時回傳 0
    }
};
