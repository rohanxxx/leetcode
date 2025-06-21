class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> left, right;

        for(auto n: nums){
            if(n % 2 == 0){
                left.push_back(n);
            }
            else{
                right.push_back(n);
            }
        }

        for(auto r: right){
            left.push_back(r);
        }

        return left;
    }
};