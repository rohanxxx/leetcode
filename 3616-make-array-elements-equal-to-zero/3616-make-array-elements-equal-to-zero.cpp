class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=0,tot=0,ans=0;
        for(auto ele:nums){
            sum+=ele;
        }
        for(auto ele:nums ){
            if(ele==0) {
                if(tot*2==sum) ans+=2;
                else{
                    if(tot*2-1 == sum) ans++;
                    if(tot*2+1 == sum) ans++;
                }
            }
            tot+=ele;
        }
        return ans;
    }
};