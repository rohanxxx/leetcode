class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<int, string> keys;
        
        for(int i = 97; i <= 122; i++){
            string x = ""; x+=i;
            keys[i-97] = x;
        }

        unordered_map<string, vector<string>> mp;
        for(string& s: strings){
            int n = s.length();
            if(n == 1){
                string x = ""; x+= 95;
                // cout << "x: " << x << endl;
                mp[x].push_back(s);
                continue;
            }

            string index = "";
            for(int i = 1; i < n; i++){
                int dif = (s[i]-s[i-1]+26)%26;
                index += dif;
            }
            mp[index].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;;
    }
};