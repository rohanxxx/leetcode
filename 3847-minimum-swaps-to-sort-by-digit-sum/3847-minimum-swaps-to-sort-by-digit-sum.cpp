/*
    Input: nums = [18,43,34,16]
    Output: 2
    [18,43,34,16]
     9  7   7  7
*/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int sum = 0;
            map[num] = i;
            while(num){
                int pop = num % 10;
                num = num / 10;
                sum += pop;
            }
            pq.push({sum, nums[i]});
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            int sum = pq.top()[0];
            int num = pq.top()[1];
            int index = map[num];
            pq.pop();
            if(nums[i] != num){
                map[nums[i]] = index;
                //map[nums[index]] = i;
                swap(nums[i], nums[index]);
                count++;
            }
        }
        return count;
    }
};