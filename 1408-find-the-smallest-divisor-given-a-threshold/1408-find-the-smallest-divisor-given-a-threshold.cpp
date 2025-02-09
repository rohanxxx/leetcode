class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int low = 1, high = maxElement, ans = 0;
        
        while(low <= high){
            int sum = 0;
            int mid = (low+high)/2;
            for(int num: nums){
                if(num % mid){
                    sum += ((num / mid) + 1);
                    continue;
                }
                sum += (num / mid);
            }

            if(sum > threshold){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};