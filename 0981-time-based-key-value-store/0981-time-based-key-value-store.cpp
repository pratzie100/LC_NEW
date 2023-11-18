class TimeMap {
public:
    TimeMap() {
   
    }
    vector<pair<string,pair<string,int>>>v;
    void set(string key, string value, int timestamp) {
        v.push_back(make_pair(key,make_pair(value,timestamp)));
    }
    
    string get(string key, int timestamp) {
        for(int i=v.size()-1;i>=0;i--)
        {
            const auto& entry=v[i];
            if(entry.first==key && entry.second.second<=timestamp)
                return entry.second.first;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */