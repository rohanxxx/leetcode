/*
            0  1 2. 3 4
    nums = [1,-1,5,-2,3], k = 3 sample output is 4
    prefixSumMap:

    1 -> 0 1-3 -> -2 if map exists
    0 -> 1 0-3 -> -3
    5 -> 2 5-3 -> 2     3
           3-3 -> 0.  ans = max(currentIndex - prefixSumMap[0]+1, ans); 3 - 0 + 1 = 4
*/          
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        //first declare variables like ans and hash map
        int ans = 0;
        long long sum = 0;
        int n = nums.size();

        //SC: O(N)
        unordered_map<int, int> sumMap;

        //iterate over nums
        //TC: O(N)
        for(int i = 0; i < n; i++){
            //do the sum
            sum += nums[i];
            if(sum == k){
                ans = i - 0 + 1;
            }
            //first check sum-k exists in the map
            //if so then we will update our answer
            //if sum-k value found in the map
            //O(1) operation
            if(sumMap.find((long long)sum-k) != sumMap.end()){
                ans = max(ans, i - sumMap[sum-k]);
                //cout << "ans: " << ans << endl << endl;
            }
            //here we will be mapping the sum to current index
            if(sumMap.find(sum) == sumMap.end()){
                sumMap[sum] = i;
            }
        }

        return ans;
    }
};