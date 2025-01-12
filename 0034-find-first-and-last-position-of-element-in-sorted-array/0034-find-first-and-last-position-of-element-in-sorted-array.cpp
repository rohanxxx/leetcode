class Solution {
public:
    int findOccurrence(vector<int>& nums, int target, bool isFirst){
        int occurrence;
        if(isFirst) occurrence = INT_MAX;
        else occurrence = INT_MIN;

        int left = 0, right = (int)nums.size()-1;
        
        while(left <= right){
            int mid = (left + right)/2;
            // cout << "mid: " << mid << endl;
            if(nums[mid] == target){
            
                if(isFirst) {
                    if((mid-1)>= 0 && nums[mid-1] == target){
                        occurrence = min(mid-1, occurrence);
                    }
                    occurrence = min(mid, occurrence);
                    right = mid-1;

                }
                else {
                    occurrence = max(mid, occurrence);
                    left = mid+1;
                }
                continue;
            }

            if(nums[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        if(occurrence == INT_MAX || occurrence == INT_MIN) return -1;
        return occurrence;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findOccurrence(nums, target, true);
        int last = findOccurrence(nums, target, false);
        return {first, last};
    }
};