class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});

        string ans = "";
        while(!pq.empty()){
            pair<int, char> p = pq.top(); pq.pop();
            int count = p.first;
            char c = p.second;
            if(ans.length() >= 2 && ans[ans.length()-1] == c && ans[ans.length()-2] == c){
                if(pq.empty()) break;
                pair<int, char> temp = pq.top(); pq.pop();
                ans += temp.second;
                if(temp.first-1 > 0){
                    pq.push({temp.first-1, temp.second});
                }
            }
            else{
                count--;
                ans+= c;
            }

            if(count){
                pq.push({count, c});
            }
        }

        return ans;
    }
};