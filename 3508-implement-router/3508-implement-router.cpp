class Router {
private:
    int size;
    unordered_map<long long, array<int, 3>> packets; // key -> {source, dest, time}
    unordered_map<int, vector<int>> counts;          // dest -> sorted timestamps
    queue<long long> q;                              // FIFO order

    long long encode(int source, int destination, int timestamp) {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }

    int lowerBound(const vector<int>& list, int target) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list[mid] < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    int upperBound(const vector<int>& list, int target) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list[mid] <= target) low = mid + 1;
            else high = mid;
        }
        return low;
    }

public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        long long key = encode(source, destination, timestamp);

        if (packets.count(key)) return false; // duplicate

        if ((int)packets.size() >= size) forwardPacket(); // remove oldest

        packets[key] = {source, destination, timestamp};
        q.push(key);
        counts[destination].push_back(timestamp); // timestamps are in increasing order

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};

        long long key = q.front();
        q.pop();

        auto packet = packets[key];
        packets.erase(key);

        auto &list = counts[packet[1]];
        list.erase(list.begin()); // remove oldest timestamp for that destination

        return {packet[0], packet[1], packet[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = counts.find(destination);
        if (it == counts.end() || it->second.empty()) return 0;

        auto &list = it->second;
        int left = lowerBound(list, startTime);
        int right = upperBound(list, endTime);
        return right - left;
    }
};