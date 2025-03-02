class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> sortedTasks;
        for(int i = 0; i < tasks.size(); i++){
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(sortedTasks.begin(), sortedTasks.end());

        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int index = 0;
        long long curTime = 0;

        while(index < tasks.size() || !pq.empty()){
            if(pq.empty() && curTime < sortedTasks[index][0]){
                curTime = sortedTasks[index][0];
            }
            while(index < sortedTasks.size() && sortedTasks[index][0] <= curTime ){
                pq.push({sortedTasks[index][1], sortedTasks[index][2]});
                index++;
            }
            auto [processingTime, idx] = pq.top();
            pq.pop();

            curTime += processingTime;
            ans.push_back(idx);
        }

        return ans;
    }
};