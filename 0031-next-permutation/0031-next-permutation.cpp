class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i > 0){
            if(nums[i] <= nums[i-1]) i--;
            else break;
        }
        cout << "i: " << i << endl;
        if(i){
            // cout << "nums[i-1]: " << nums[i-1] << endl;
            // cout << "nums[i]: " << nums[i] << endl;
            int j = nums.size()-1;
            while(nums[i-1] >= nums[j]) j--;
            swap(nums[i-1], nums[j]);
        }
        // cout << "i: " << i << endl;
        /*for(int num: nums){
            cout << num << " ";
        }
        cout << endl;*/
        sort(nums.begin()+i, nums.end());
    }
};