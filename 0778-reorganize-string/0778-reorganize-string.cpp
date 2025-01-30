class Solution {
public:
    string reorganizeString(string s) {
        int majorityElement;
        if(s.length()%2){
            majorityElement = (1+s.length())/2;
        }
        else{
            majorityElement = s.length()/2;
        }

        unordered_map<char, int> mp;
        for(char c: s){
            if(++mp[c] > majorityElement){
                return "";
            }
        }

        priority_queue<pair<int, char>> pq;
        for(pair<char, int> p: mp){
            pair<int, char> pair = {p.second, p.first};
            pq.push(pair);
        }

        int i = 0;
        string ans((int)s.length(), '_');
        while(!pq.empty()){
            int top = pq.top().first;
            char c = pq.top().second; 
            
            pq.pop();
            while(top-- != 0){
                ans[i] = c;
                i += 2;
                if(i > (int)s.length()-1) {
                    i = 1;
                }
            }
        }
        return ans;
    }
};