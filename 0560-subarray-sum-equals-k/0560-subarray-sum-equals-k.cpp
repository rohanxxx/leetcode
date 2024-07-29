class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int prefix_sum = 0, total_sub_arr = 0, diff = 0;
        umap[prefix_sum]++;
        
        for(int i = 0; i < nums.size(); i++){
            prefix_sum += nums[i];
            diff = prefix_sum - k;
            cout << "prefix_sum: " << prefix_sum << endl;
            cout << "diff: " << diff << endl;
            
            if(umap.find(diff) != umap.end()){
                total_sub_arr += umap[diff];
                cout << "total_sub_arr: " << total_sub_arr << endl;
            }
            
            umap[prefix_sum]++;
        }
        
        return total_sub_arr;
        
    }
};