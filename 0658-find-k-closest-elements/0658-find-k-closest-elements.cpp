class Solution {
public:
    int binarySearch(int x, vector<int>& arr){
        int left = 0;
        int right = arr.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(arr[mid] == x) return mid;
            if(arr[mid] < x) left = mid+1;
            else right = mid-1;
        }
        return left;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = binarySearch(x, arr);
        int n = arr.size();
        int a = index-1;
        int b = index;

        vector<int> ans;

        // Two pointers expanding from the center
        while(k > 0) {
            if(a < 0) {
                ans.push_back(arr[b++]);
            } else if(b >= n) {
                ans.push_back(arr[a--]);
            } else {
                int eq1 = abs(arr[a] - x);
                int eq2 = abs(arr[b] - x);
                if(eq1 <= eq2) ans.push_back(arr[a--]);
                else ans.push_back(arr[b++]);
            }
            k--;
        }

        sort(ans.begin(), ans.end()); // required as output must be sorted
        return ans;
    }
};