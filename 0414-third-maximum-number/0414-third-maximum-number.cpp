class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        //O(NLog(3))
        for(auto num: set){
            pq.push(num);
            if(pq.size() > 3) {
                pq.pop();
            }
        }

        if(pq.size() < 3){
            pq.pop();
        }

        return pq.top();
    }
};