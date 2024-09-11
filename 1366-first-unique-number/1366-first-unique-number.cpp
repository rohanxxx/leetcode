class FirstUnique {
public:
    queue<int> unique;
    unordered_map<int, int> counts;
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            // Just use the in-class function to add new number
            add(num);
        }
    }
    
    int showFirstUnique() {
        // If there is no unique number return -1
        if (unique.empty()) {
            return -1;
        }
        return unique.front();
    }
    
    void add(int value) {
        // After added the value, if the count of the value is 1, add it to queue
        if (++counts[value] == 1) {
            unique.push(value);
        }
        // remove the number which is no longer unique
        while (!unique.empty() && counts[unique.front()] > 1) {
            unique.pop();
        }
    }
};


/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */