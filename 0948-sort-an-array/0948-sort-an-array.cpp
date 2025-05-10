/*
*/

class Solution {
public:
    //vector<int> ans;
    void merge(vector<int>& nums, int left, int mid, int right){
        int p1 = left;
        int p2 = mid+1;
        
        vector<int> temp;
        while(p1 <= mid && p2 <= right){
            if(nums[p1] <= nums[p2]){
                temp.push_back(nums[p1++]);
            }
            else{
                temp.push_back(nums[p2++]);
            }
        }

        while(p1 <= mid){
            temp.push_back(nums[p1++]);
        }
        while(p2 <= right){
            temp.push_back(nums[p2++]);
        }


        //we are transferring all the sorted cells to the original array
        for(int i = left; i <= right; i++){
            nums[i] = temp[i-left];
        }
    }
    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int mid = (left+right)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        //ans.resize(n);
        mergeSort(nums, 0, n-1);
        return nums;
    }
};