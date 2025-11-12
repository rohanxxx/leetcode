class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        //TC: O(N), SC: O(1)
        for(string& ops: operations){
            if(ops == "--X" || ops == "X--") val--;
            if(ops == "++X" || ops == "X++") val++;
        }
        return val;
    }
};