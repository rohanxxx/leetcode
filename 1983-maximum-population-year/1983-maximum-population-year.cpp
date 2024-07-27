class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> v(2051, 0);
        for(auto& log: logs){
            v[log[0]]++;
            v[log[1]]--;
        }

        int year = 0;
        int aliveCount = INT_MIN;
        for(int i = 1950; i < v.size(); i++){
            v[i] += v[i-1];
            if(aliveCount < v[i]){
                year = i;
                aliveCount = v[i];
            }
        }

        return year;
    }
};