class LRUCache {
public:
    unordered_map<int,int>m;
    unordered_map<int,list<int>::iterator>itMap;
    list<int>L;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(m.count(key)) {
            L.erase(itMap[key]);
            L.push_front(key);
            itMap[key]=L.begin();
            return m[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            L.erase(itMap[key]);
            L.push_front(key);
            itMap[key]=L.begin();
            m[key]=value;
            return;
        }
        else{
            if(m.size()==capacity){
                int lru=L.back();
                L.pop_back();
                itMap.erase(lru);
                m.erase(lru);
            }
            L.push_front(key);
            itMap[key]=L.begin();
            m[key]=value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */