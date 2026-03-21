/*
    M bouquet
    k adjacent flowers

    n flowers ith flower blooms in bloomDay[i] can be used exactly one bouquet

    return the minimum # of days to make m bouquet

    bloomDay = [1,10,3,10,2], m = 3, k = 1
    bloomDay = [1,10,3,10,2], m = 3, k = 2
    
    bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
*/
class Solution {
public:
    bool isPossible(int mid, int& m, int& k, vector<int>& bloomDay){
        int n = bloomDay.size();
        
        int mCount = 0;
        int kCount = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= mid){
                kCount++;
            }
            else{
                if(kCount >= k){
                    mCount += (kCount/k);
                }
                kCount = 0;
            }
        }

        if(kCount >= k){
            mCount += (kCount/k);
        }
        

        return mCount >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        //edge case
        if(n < (long long)m*k) return -1;
        //first find the range
        int minDay = INT_MAX;
        int maxDay = INT_MIN;

        for(auto it: bloomDay){
            minDay = min(minDay, it);
            maxDay = max(maxDay, it);
        }

        //O(N*log(range))
        while(minDay <= maxDay){
            int mid = minDay + (maxDay - minDay)/2;
            if(isPossible(mid, m, k, bloomDay)){
                maxDay = mid-1;
            }
            else{
                minDay = mid+1;
            }
        }
        return minDay;
    }
};