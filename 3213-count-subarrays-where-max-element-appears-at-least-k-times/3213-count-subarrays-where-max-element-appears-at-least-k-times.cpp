/*
    Input: nums = [1,3,2,3,3], k = 2
    Output: 6
            0 1 2 3 4
    nums = [1,3,2,3,3]
     1 3 2 3
     1 3 2 3 3

     3 2 3 3
     3 2 3

     2 3 3
     3 3

            0 1 2 3 4
    nums = [1,3,2,3,3] n = 5

    n - 3 = 2
    n - 3 = 2
    n - 4 = 1
    n - 4 = 1
    left = 1 -> 2 -> 3

    3 -> 1
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // first find the max element
        int maxElement = INT_MIN;
        unordered_map<int, int> freqMap;
        //TC: O(N)
        for(auto it: nums){
            freqMap[it]++;
            if(it > maxElement){
                //then update the maxElement
                maxElement = it;
            }
        }

        //now use a sliding window technique to find the contiguous subsequence
        long long n = nums.size();
        long long left = 0;
        long long ans = 0;
        unordered_map<int, int> curFreq;
        for(long long right = 0; right < n; right++){
            if(maxElement == nums[right]){
                curFreq[maxElement]++;
            }
            while(left <= right && curFreq[maxElement] >= k){
                ans += ((long long)n - right);
                if(nums[left] == maxElement){
                    curFreq[maxElement]--;
                    if(curFreq[maxElement] == 0){
                        curFreq.erase(maxElement);
                    }
                }

                left++;
            }
            
        }

        return ans;
    }
};