#define ll long long  
class Solution {
public:

int maximumLength(vector<int>& nums) {
    int n=nums.size(); 
    unordered_map<ll,ll> temp, mp;
	
    for(auto num: nums) temp[num]++;       
    sort(nums.begin(), nums.end(), greater<int>());
       
    for(int i=0; i<n; i++){
        if(nums[i]==1) continue;   // Leave the case for element 1 because we are going to handle it separately below.
        ll x=(ll)nums[i]*(ll)nums[i];
        
        if((ll)temp[x] && temp[nums[i]]>=2) mp[nums[i]]=2+mp[x];  // Think about this exmaple it helps to understand this line:  [16,4,4,2,2]                                                                   
        else mp[nums[i]]=1; 
    }
    
    ll maxi=1;
    for(auto i: mp) maxi=max(maxi, i.second);
    maxi = max(maxi, temp[1]-(temp[1]%2==0));    // If occurence of 1 is Even then subtract 1 else do nothing             
    return maxi;
}


};