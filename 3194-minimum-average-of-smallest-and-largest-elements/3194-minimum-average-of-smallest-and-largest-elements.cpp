class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        //TC: O(NlogN+N)
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums.size()-1;

        double minAvg = INT_MAX;
        while(left < right){
            double avg = (double)nums[left]+((double)(nums[right]-nums[left])/2);
            minAvg = min(avg, minAvg);
            left++;
            right--;
        }

        return minAvg;
    }
};