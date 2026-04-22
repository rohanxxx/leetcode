/*
    target = [3,1,1,2]
              3,1,1,2

    3+

    3 1 1 2
    3 1 1 2
    3+1 => 4

    prev >= curr

    1,2,3,2,1
    1,2,3,2,1
    1+1+1

    we have to update the peak and fall in each increment


*/
class Solution {
public:
    //TC: O(N)
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        int currPeak;
        int opsCount = 0;
        //TC: O(N)
        for(int i = 0; i < n; i++){
            if(i == 0){
                currPeak = target[i];
                opsCount += (currPeak);
                continue;
            }
            if(target[i] > currPeak){
                opsCount += (target[i]-currPeak);
            }
            currPeak = target[i];
        }
        return opsCount;
    }
};