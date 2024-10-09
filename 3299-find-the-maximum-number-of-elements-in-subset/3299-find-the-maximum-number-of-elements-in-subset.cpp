class Solution {
public:
int maximumLength(vector<int>& nums) {
    int n=nums.size(); 
    
    unordered_map<long,long> temp, mp;
	
    sort(nums.rbegin(), nums.rend());
    
    for(auto num: nums) temp[num]++;       
    for(int i=0; i<n; i++){
        if(nums[i]==1) continue;
        long x=(long)nums[i]*(long)nums[i];
        
        if((long)temp[x] && temp[nums[i]]>=2) mp[nums[i]] = 2+mp[x];                                                                
        else mp[nums[i]] = 1; 
    }
    
    long maxi=1;
    for(auto i: mp) maxi=max(maxi, i.second);
    
    maxi = max(maxi, temp[1]-(temp[1]%2==0));   
    
    return maxi;
}
};