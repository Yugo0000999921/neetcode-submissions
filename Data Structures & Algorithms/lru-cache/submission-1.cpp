class LRUCache {
    int cap;
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator> mp; // key→場所
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        
        auto it = mp[key];
        // 削除して追加->移動
        int val = it->second;
        dll.erase(it);
        dll.push_front({key,val});

        mp[key] = dll.begin();

        return dll.begin()->second;
    }
    
    void put(int key, int value) {
        //すでにある場合 まず削除
        if(mp.count(key)){
            dll.erase(mp[key]);
        }
        dll.push_front({key,value});
        mp[key] = dll.begin();

        if(dll.size()>cap){
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }
    }
};
