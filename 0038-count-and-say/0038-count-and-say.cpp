class Solution {
public:
    string countAndSay(int n) {
        string currStr = "1";
        for(int i = 2; i <= n; i++){
            string nextStr = "";
            int k = 0; int count = 0;
            cout << "count: " << count << endl;
            for(int j = 0; j < currStr.length(); j++){
                if(currStr[j] == currStr[k]) count++;
                else{
                    nextStr += to_string(count) + currStr[k];
                    count = 1; k = j;
                }
                if(j == currStr.length()-1){
                    nextStr += to_string(count) + currStr[k];
                    break;
                }
            }
            currStr = nextStr;
        }
        return currStr;
    }
};