class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;
        unordered_map<int, int> mp;
        for(int i = 0; (i+k-1) < nums.size(); i++){
            if(i == 0){
                for(int j = 0; j < k; j++){
                    mp[nums[j]]++;
                }
            }
            if(i != 0){
                mp[nums[i-1]]--;
                mp[nums[i+(k-1)]]++;
            }

            priority_queue<pair<int, int>> pq;
            for(auto pair: mp){
                pq.push({pair.second, pair.first});
            }

            int sum = 0;
            for(int j = 0; j < x && !pq.empty(); j++){
                pair<int,int> p = pq.top();
                for(int k = 0; k < p.first; k++){
                    sum += p.second;
                }
                pq.pop();
            }
            result.push_back(sum);
        }
        return result;
    }
};