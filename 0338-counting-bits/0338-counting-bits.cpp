class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
    
        for(int i = 1; i < n+1; i++){
            int decVal = i;
            int count = 0;
            while(decVal > 0){
                count += decVal & 1; // checking if least significant number is 1
                decVal >>= 1; // right shift by 1
            }
            ans.push_back(count);
        }
        return ans;
    }
};