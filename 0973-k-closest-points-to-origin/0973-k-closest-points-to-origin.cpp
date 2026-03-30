class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //vector<pair<int, vector<int>>> disVec;
        //maxHeap
        priority_queue<pair<int, vector<int>>> pq;
        for(int i = 0; i < points.size(); i++){
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({dis, points[i]});
            if((int)pq.size() > k){
                pq.pop();
            }
        }

        //sort(disVec.begin(), disVec.end());
        vector<vector<int>> ans(k);
        for(int i = k-1; i >= 0; i--){
            vector<int> point = pq.top().second; pq.pop();
            ans[i] = point;
        }

        return ans;
    }
};