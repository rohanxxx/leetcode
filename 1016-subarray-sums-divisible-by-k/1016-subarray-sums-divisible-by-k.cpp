class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        cout << (-1) % k << endl;
        int count = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int remainder = sum % k;
            if(remainder < 0) remainder += k;
            if(mp.find(remainder) != mp.end()) count += mp[remainder];
            mp[remainder]++;
        }
        return count;
    }
};