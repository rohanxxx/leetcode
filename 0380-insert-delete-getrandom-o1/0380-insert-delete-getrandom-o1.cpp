class RandomizedSet {
private:
    vector<int> uset;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(uset.empty()){
            uset.push_back(val);
            return true;
        }

        auto it = find(uset.begin(), uset.end(), val);
        if (it != uset.end()) {
            return false;
        }

        uset.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(uset.empty()){
            return false;
        }
        // Find and erase element 30 from the vector
        auto it = find(uset.begin(), uset.end(), val);
        if (it != uset.end()) {
            uset.erase(it);  
            return true;
        }

        return false;
    }
    
    int getRandom() {
        int randomIndex = rand() % uset.size();
        int randomElement = uset[randomIndex];
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