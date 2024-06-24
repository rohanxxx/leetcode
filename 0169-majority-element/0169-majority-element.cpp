class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int majorityElement = 0, maxCount = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            if(maxCount < mp[nums[i]]){
                cout << "nums[" << i << "]: " << nums[i] << endl;
                maxCount = mp[nums[i]];
                majorityElement = nums[i];
            }
        }
        cout << "majorityElement: " << majorityElement << endl;
        if(mp[majorityElement] > nums.size()/2) return majorityElement;
        for(auto it = mp.begin(); it != mp.end(); it++){
            cout << "it->first: " << it->first << ", " << "it->second: " << it->second << endl;
        }
        return -1;
    }
};