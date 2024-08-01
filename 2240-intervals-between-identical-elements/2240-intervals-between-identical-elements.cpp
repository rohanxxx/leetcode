class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
        vector<long long> v(arr.size());
        long long int s1,s2,k,ans;
        for(auto &i: mp){
            s1 = 0, s2 = 0;
            for(auto j: i.second){
                s2 = s2 + j;
            }
            // cout<<i.first<<" "<<s2<<endl;
            for(k = 0; k < i.second.size(); k++){
                // cout<<i.second[k];
                ans = (s2-(i.second.size()-k)*i.second[k]) + abs(s1-k*i.second[k]);
                v[i.second[k]] = ans;
                s2 -= i.second[k];
                s1 += i.second[k];
                
            }
        }
        return v;
    }
};