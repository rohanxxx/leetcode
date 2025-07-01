class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, middle, right;
        for(auto& num: nums){
            if(num < pivot) left.push_back(num);
            if(num == pivot) middle.push_back(num);
            if(num > pivot) right.push_back(num);
        }
        for(auto& it: middle) left.push_back(it);
        for(auto& it: right) left.push_back(it);

        return left;
    }
};