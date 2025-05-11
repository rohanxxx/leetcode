class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        //for frequency count
        map<int,int> freq;
        int left = 0, right = 0;

        long long count = 0;
        while(right < n){
            freq[nums[right]]++;
            while(freq.rbegin()->first - freq.begin()->first > 2){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            count += right-left+1;
            right++;
        }
        return count;
    }
};