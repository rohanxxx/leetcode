class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int m=sequence.size();
        int n=word.size();
        int maxi=INT_MIN;
        int ans=0;
        for(int i=0;i<=m-n;i++){
            if(sequence.substr(i,n)==word){
                ans++;
                i+=(n-1);
            }
            else {
                if(ans){
                maxi=max(ans,maxi);
                i-=n-1;
                ans=0;
                }
            }
        }
        maxi=max(ans,maxi);
        return maxi;
    }
};