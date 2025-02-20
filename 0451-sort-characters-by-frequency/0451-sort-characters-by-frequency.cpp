class Solution {
public:
    string frequencySort(string s) {
        if(s.length() < 3) return s;
        
        unordered_map<char, int> mp;
        for(auto& c: s) mp[c]++;

        priority_queue<pair<int, char>> pq;
        for(auto i: mp){
            pq.push({i.second, i.first});
        }

        string freq = "";
        while(!pq.empty()){
            pair<int, char> p = pq.top(); pq.pop();
            for(int i = 0; i < p.first; i++){
                freq += p.second;
            }
        }       
        return freq;
    }
};