class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ans;
        unordered_map<int, int> map;
        for(auto& num: nums){
            map[a*num*num+b*num+c]++;
        }
        for(int i = -1e6; i <= 1e6; i++){
            if(map.find(i) != map.end()){
                for(int j = 0; j < map[i]; j++){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};