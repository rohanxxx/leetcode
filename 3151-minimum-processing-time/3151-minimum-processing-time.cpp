class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        sort(processorTime.rbegin(), processorTime.rend());
        int chunkSize = tasks.size()/processorTime.size();
        int start = 0;

        int minTime = INT_MIN;
        for(int i = 0; i < tasks.size(); i++){

            for(int j = start; j < tasks.size() && j < chunkSize; j++){
                minTime = max(minTime, processorTime[i]+tasks[j]);
            }

            start = chunkSize;
            chunkSize += (tasks.size()/processorTime.size());
        }

        return minTime;
    }
};