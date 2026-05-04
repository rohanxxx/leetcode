class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return 0;
        
        int left = 0; 
        int right = arr.size()-1;
        int mid; //= INT_MIN;
        
        while(left < right){
            mid = (left+right)/2;
            if(arr[mid] < arr[mid+1]) left = mid+1;
            else right = mid;
        }
        return left;
    }
};