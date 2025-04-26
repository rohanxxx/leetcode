class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longestStreak = 0;
        for(auto num: set){
            if(set.count(num-1) == 0){
                int curNum = num;
                int streak = 1;
                while(set.count(curNum+1)){
                    curNum++;
                    streak++;
                }
                longestStreak = max(longestStreak, streak);
            }
        }
        return longestStreak;
    }
};