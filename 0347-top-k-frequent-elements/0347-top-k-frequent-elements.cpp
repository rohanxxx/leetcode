class Solution {
public:
    //TC: O(4N+K) => O(N+K)
    //SC: O(N+N) => O(N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        //max freq of an element would be n
        vector<vector<int>> bucket(n+1);

        unordered_map<int, int> freq;
        //TC: O(N)
        for(int num: nums){
            freq[num]++;
        }

        //fill the bucked according the elements freq level
        //TC: O(N)
        for(auto it: freq){
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;
        //TC: O(N+K)
        for(int i = n; i >= 0; i--){
            if(k-bucket[i].size() >= 0){
                for(auto it: bucket[i]){
                    ans.push_back(it);
                }
                k-= bucket[i].size();
            }
            if(k <= 0){
                break;
            }
        }

        return ans;
        
    }
};