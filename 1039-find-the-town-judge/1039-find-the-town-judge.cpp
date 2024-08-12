class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() < 1 && n == 1) return 1;
        if(trust.size() < 1) return -1;
        unordered_map<int, int> trustCount;
        unordered_set <int> trusts;
        for(auto t: trust){
            trusts.insert(t[0]);
            if(trustCount.find(t[0]) != trustCount.end()) trustCount.insert({t[0], 0});
            trustCount[t[1]]++;
        }

        for(auto it = trustCount.begin(); it != trustCount.end(); it++){
            // cout << "it->first: " << it->first << endl;
            //cout << "it->second: " << it->second << endl;
            
            if(it->second == n-1 && trusts.find(it->first) == trusts.end()){
                return it->first;
            }
        }

        return -1;
    }
};