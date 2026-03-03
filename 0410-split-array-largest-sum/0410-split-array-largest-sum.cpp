class Solution {
public:
    int countSplits(vector<int>& nums, int hi){
        int splits = 1;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > hi){
                splits++;
                sum = nums[i];
            }
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        //TC: O(N+N) = O(2N) = O(N)
        int lo = *max_element(nums.begin(), nums.end()); //gives max element
        int hi = accumulate(nums.begin(), nums.end(), 0); //gives sum of arr

        //TC: O(log(sum))
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            int count = countSplits(nums, mid);
            if(count > k) lo = mid+1;
            else hi = mid-1;
        }

        return lo;
    }
};