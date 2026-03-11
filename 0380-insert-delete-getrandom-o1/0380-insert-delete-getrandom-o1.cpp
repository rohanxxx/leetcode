class RandomizedSet {
private:
    unordered_set<int> uset;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(uset.empty()){
            uset.insert(val);
            return true;
        }

        auto it = uset.find(val);
        if (it != uset.end()) {
            return false;
        }

        uset.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(uset.empty()){
            return false;
        }
        // Find and erase element 30 from the vector
        auto it = uset.find(val);
        if (it != uset.end()) {
            uset.erase(it);  
            return true;
        }

        return false;
    }
    
    int getRandom() {
        int randomIndex = rand() % uset.size();
        auto it = uset.begin();
        advance(it, randomIndex);
        int randomElement = *it;
        return randomElement;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */