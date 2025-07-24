/*
                   0   1  2  3 4
    Input: nums = [18,43,36,13,7]
                    9  7. 9. 4 7
    Output: 54
*/
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
        
        int maxPairSum = INT_MIN;
        
        //TC: O(Nlog2)
        for(auto it: nums){
            int num = it;
            int digitSum = 0;
            while(num){
                digitSum += (num % 10);
                num /= 10;
            }
            map[digitSum].push(it);
            if(map[digitSum].size() > 2){
                map[digitSum].pop();
            } 
        }

        //TC: O(N)
        for(auto& it: map){
            int curSum = 0;
            if(it.second.size() == 2){
                //TC:O(2)
                while(!it.second.empty()){
                    int num = it.second.top();
                    curSum += num;
                    it.second.pop();
                }
                maxPairSum = max(maxPairSum, curSum);
            }
        }

        if(maxPairSum == INT_MIN) return -1;

        return maxPairSum;
    }
};