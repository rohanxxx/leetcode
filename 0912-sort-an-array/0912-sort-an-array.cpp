class Solution {
public:
    vector<int> merge(vector<int> a, vector<int> b){
        vector<int> temp;
        
        int i = 0, j = 0;
        while(i < (int)a.size() && j < (int)b.size()){
            if(a[i] <= b[j]){
                temp.push_back(a[i++]);
            }
            else{
                temp.push_back(b[j++]);
            }
        }

        while(i < (int)a.size()){
            temp.push_back(a[i]);
            i++;
        }
        while(j < (int)b.size()){
            temp.push_back(b[j]);
            j++;
        }
        return temp;
    }

    vector<int> mergeSort(int left, int right, vector<int>& nums){
        if(left > right) return {};
        if(left == right) return {nums[left]};

        int mid = left + (right-left)/2;
        vector<int> leftSide = mergeSort(left, mid, nums);
        vector<int> rightSide = mergeSort(mid+1, right, nums);

        return merge(leftSide, rightSide);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0, n-1, nums);
    }
};