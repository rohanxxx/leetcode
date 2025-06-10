/*
    [6,2,6,5,1,2]
    0 1 2 3 4 5
    1 2 2 5 6 6
    (6,6) (2,5) (1,2)
    6 + 2 + 1

    0 1 2 3
    1 2 3 4
    1 + 3 => 4
*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto& num: nums) freq[num]++;
        int count = 0;
        int ans = 0;

        vector<int> v;
        for(int i = -1e4; i <= 1e4; i++){
            if(freq.find(i) != freq.end()){
                for(int it = 0; it < freq[i]; it++) v.push_back(i);
            }
        }
        for(int i = 0; i < nums.size(); i+=2){
            ans += v[i];
        }
        return ans;
    }
};