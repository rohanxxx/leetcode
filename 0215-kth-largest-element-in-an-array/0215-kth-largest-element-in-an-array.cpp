class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num: nums){
            pq.push(num);
        }
        int ans;
        while(k > 0){
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};