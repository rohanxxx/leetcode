/*
Input: target = [1,2,3,2,1]
      initial =  1 2 3 2 1 -> 0 0 0 0 0 -> 1 1 1 0 0 -> 1 2 2 1 0 -> 1 2 3 2 1
                 0 1 2 3 4
Output: 3
Input: target = [3,1,5,4,2] output = 7
                 0 1 2 3 4
    operationCount = 1;

Input: target = [3,1,1,2] output  4
    3-1 = 2+1 = 3
    if(i == 0) operationCount += (nums[i]-1);
    if(nums[i] > nums[i-1]) operationCount += (nums[i]-nums[i-1]);
*/
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int operationCount = 1;
        for(int i = 0; i < n; i++){
            if(i == 0){
                operationCount += (target[i]-1);
                continue;
            }
            if(target[i] > target[i-1]){
                operationCount += (target[i]-target[i-1]);
            }
        }
        return operationCount;
    }
};