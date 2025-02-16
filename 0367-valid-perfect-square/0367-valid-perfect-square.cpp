class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while(left <= right){
            int mid = (left+right)/2;
            if(mid*(long long)mid == (long long)num) return true;
            if(mid*(long long)mid < (long long)num) left = mid+1;
            if(mid*(long long)mid > (long long)num) right = mid-1;
        }
        return false;
    }
};