class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        //TC: Nlog(k)
        for(int num: nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop(); //O(1)
            }
        }
        int ans = pq.top();

        return ans;
    }
};