class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hashMap(n+1, 0);

        for(int i = 0; i < n; i++){
            hashMap[nums[i]]++;
        }

        int duplicate = -1, missing = -1;
        for(int i = 1; i <= n; i++){
            if(hashMap[i] > 1){
                duplicate = i;
            }
            if(hashMap[i] == 0){
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};