class MyHashMap {
private:
    const int SIZE = 1009;
    vector<vector<pair<int, int>>> mymap;
    int hash(int key) {
        return key % SIZE;
    }
public:
    MyHashMap() {
        mymap.resize(SIZE);
    }
    
    void put(int key, int value) {
        int index = hash(key);

        // find the key if exists, or create the key

        for (auto &p: mymap[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        mymap[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);

        for (auto &p: mymap[index]) {
            if (p.first == key) return p.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);

        for (auto it = mymap[index].begin(); it != mymap[index].end(); ++it) {
            if (it->first == key) {
                mymap[index].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */