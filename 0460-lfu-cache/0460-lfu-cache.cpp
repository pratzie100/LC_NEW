class LFUCache {
public:
    unordered_map<int, int> keyFreq; // key -> frequency
    unordered_map<int, list<int>> freqList; // freq -> list of keys (LRU order)
    unordered_map<int, pair<int, list<int>::iterator>> m; // key -> {value, iterator to key's position in freqList[keyFreq[key]]}
    int minfreq;
    int capacity;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minfreq = 0;
    }

    void updateFrequency(int key) {
        int oldfreq = keyFreq[key];
        auto it = m[key].second;

        // Remove key from current freq list
        freqList[oldfreq].erase(it);

        // Update minfreq if necessary
        if (freqList[oldfreq].empty()) {
            freqList.erase(oldfreq);
            if (minfreq == oldfreq) minfreq++;
        }

        // Add key to next freq list
        int newfreq = oldfreq + 1;
        keyFreq[key] = newfreq;
        freqList[newfreq].push_front(key);
        m[key].second = freqList[newfreq].begin();
    }

    int get(int key) {
        if (!m.count(key)) return -1;
        updateFrequency(key);
        return m[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (m.count(key)) {
            m[key].first = value;
            updateFrequency(key);
            return;
        }

        if (m.size() == capacity) {
            int evictKey = freqList[minfreq].back();
            freqList[minfreq].pop_back();
            if (freqList[minfreq].empty()) freqList.erase(minfreq);
            m.erase(evictKey);
            keyFreq.erase(evictKey);
        }

        keyFreq[key] = 1;
        freqList[1].push_front(key);
        m[key] = {value, freqList[1].begin()};
        minfreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */