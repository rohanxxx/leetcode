class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(string& ops: operations){
            if(ops == "--X" || ops == "X--") val--;
            if(ops == "++X" || ops == "X++") val++;
        }
        return val;
    }
};