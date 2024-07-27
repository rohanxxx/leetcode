class NumArray {
public:
    vector<int> prefixNums;
    NumArray(vector<int>& nums) {
        this->prefixNums = nums;
        for(int i = 1; i < prefixNums.size(); i++){
            prefixNums[i] += prefixNums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        long long ans = 0;

        if(left == 0) return prefixNums[right];

        ans = prefixNums[right] - prefixNums[left-1];

        return ans;
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */