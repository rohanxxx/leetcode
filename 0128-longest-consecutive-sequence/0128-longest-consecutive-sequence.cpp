class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> set(nums.begin(), nums.end());
        int longestStreak = 1;
        for(auto num: set){
            if(!set.count(num-1)){
                int curNum = num;
                int streak = 1;
                while(set.count(curNum+1)){
                    curNum++;
                    streak++;
                }
                longestStreak = max(streak, longestStreak);
            }
        }
        return longestStreak;
    }
};