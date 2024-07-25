class Solution {
public:
    bool static compare(vector<int>& a, vector<int>& b){
        return (a[1]-a[0]) > (b[1]-b[0]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), compare);

        int energyLeft = 0, ans = 0;
        for(auto& t: tasks){
            int actual = t[0];
            int minimum = t[1];

            if(energyLeft < minimum){
                ans+= minimum-energyLeft;
                energyLeft = minimum - actual;
                continue;
            }

            energyLeft -= actual;
        }
        return ans;
    }
};