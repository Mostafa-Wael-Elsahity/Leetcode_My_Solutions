class LRUCache {
public:
    unordered_map<int,pair<int,int>>key_value;
    map<int,int>used;
    int cap,ctr=0;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(key_value.find(key)==key_value.end()) return -1;
        int pos=key_value[key].first;
        used.erase(pos);
        key_value[key].first=ctr;
        used[ctr++]=key;
        return key_value[key].second;
    }
    
    void put(int key, int value) {
        if(key_value.find(key)!=key_value.end()){
            int pos=key_value[key].first;
            used.erase(pos);
            used[ctr]=key;
            key_value[key]={ctr++,value};
            return;
        }
        used[ctr]=key;
        key_value[key]={ctr++,value};
        if(used.size()>cap){
            auto it=used.begin();
            key_value.erase(it->second);
            used.erase(it);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */