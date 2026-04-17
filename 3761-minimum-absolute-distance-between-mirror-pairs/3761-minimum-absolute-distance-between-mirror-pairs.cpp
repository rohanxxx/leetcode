/*
    return the minimum abs dist between the idx of any mirror pair
    the abs dist abs(i-j)

    reverse(nums[i] == nums[j])

    120 -> 120

    [12,21,45,33,54]
     21,12,54,33,
     0. 1. 2. 3. 4

    [21,120]
     12, 

    [120,21]
     21, 
*/
class Solution {
public:
    int reverseNum(int num){
        int newNum = 0;
        while(num > 0){
            int digit = num % 10;
            num = num/10;
            newNum = newNum * 10 + digit;
        }
        return newNum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int minDist = INT_MAX;
        unordered_map<int, int> map;
        //TC: O(Nlog2)
        for(int i = 0; i < n; i++){
            int num = nums[i];
            //if found
            //then calculate the distance
            if(map.find(num) != map.end()){
                minDist = min(minDist, abs(map[num]-i));
            }
            int x = reverseNum(num);
            map[x] = i;
        }
        if(minDist == INT_MAX){
            return -1;
        }
        return minDist;
    }
};