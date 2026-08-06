class MyHashMap {
private:
    vector<int> map;
public:
    MyHashMap() {}
    
    void put(int key, int value) {
        if(map.size() <= key){
            map.resize(key+1, -1);
        }
        map[key] = value;
    }
    
    int get(int key) {
        if(map.size() > key){
            return map[key];
        }
        return -1;
    }
    
    void remove(int key) {
        if(key < map.size()){
            map[key] = -1;
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