/*
    Input: landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]

    6

    res = min(max(waterStartTime[i], 6)+waterDuration[i], res);

    Input: landStartTime = [5], landDuration = [3], waterStartTime = [1], waterDuration = [10]
*/
class Solution {
public:
    int solve(vector<int>& startTime1, vector<int>& duration1, vector<int>& startTime2, vector<int>& duration2){
        int n = startTime1.size();
        int m = startTime2.size();
        
        int finish1 = INT_MAX, finish2 = INT_MAX;
        for(int i = 0; i < n; i++){
            finish1 = min(startTime1[i]+duration1[i], finish1);
        }
        for(int i = 0; i < m; i++){
            finish2 = min((max(finish1, startTime2[i])+duration2[i]), finish2);
        }
        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int startWithLand = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int startWithWater = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(startWithLand, startWithWater);
    }
};