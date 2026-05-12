/*.   
      0.    1.    2. 
    [1,2],[2,4],[4,8]

      0.    1.     2.      3.    4. 
    [1,3],[2,4],[10,11],[10,12],[8,9]
      0.    1.    2.     3.      4.   
    [1,3],[2,4],[10,12],[8,9],[10,11]
    2,2,10,7 ,10
    3,5,15,22,32
*/
class Solution {
public:
    bool static compare(vector<int>& a, vector<int>& b){
        return(a[1] - a[0]) > (b[1] - b[0]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), compare);
        int ans = 0;
        int energyLeft = 0, answer = 0;
        for(auto& t: tasks){
            int actual = t[0], minimum = t[1];
            if(energyLeft < minimum){
                ans += (minimum - energyLeft);
                energyLeft = minimum - actual;
                continue;
            }
            energyLeft -= actual;
        }

        return ans;
    }
};
