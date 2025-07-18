/*
    0,0,0
    0,1,6

*/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> res(n, 0);

        vector<string> s;
        stringstream ss(logs[0]);
        string token;
        
        while (getline(ss, token, ':')) s.push_back(token);
        
        st.push(stoi(s[0]));
        
        int i = 1, prev = stoi(s[2]);

        while (i < logs.size()) {
            s.clear();
            stringstream ss(logs[i]);
            while (getline(ss, token, ':')) s.push_back(token);

            if (s[1] == "start") {
                if (!st.empty())
                    res[st.top()] += stoi(s[2]) - prev;
                st.push(stoi(s[0]));
                prev = stoi(s[2]);
            } else {
                res[st.top()] += stoi(s[2]) - prev + 1;
                st.pop();
                prev = stoi(s[2]) + 1;
            }
            i++;
        }
        return res;
    }
};