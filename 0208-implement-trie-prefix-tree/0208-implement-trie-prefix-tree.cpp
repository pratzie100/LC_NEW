class Trie {
public:
    unordered_set<string>s;
    Trie() {
        
    }
    
    void insert(string word) {
        s.insert(word);
    }
    
    bool search(string word) {
        return (s.count(word)>0);
    }
    
    bool startsWith(string prefix) {
        for(string str:s)
        {
            if(str.substr(0,prefix.length())==prefix)
                return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */