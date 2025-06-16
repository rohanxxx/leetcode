class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                map[nums1[i]+nums2[j]]++;
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int sum = nums3[i] + nums4[j];
                if(map.find(((-1)*sum)) != map.end()){
                    count += map[((-1)*sum)];
                }
            }
        }

        return count;
    }
};