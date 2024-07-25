class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> frequency(n+1, 0);
        for(int i = 0; i < rounds.size()-1; i++){
            frequency[rounds[i]]++;
            if(rounds[i+1]-rounds[i] > 1){
                for(int j = rounds[i]+1; j < rounds[i+1]; j++) frequency[j]++;
            }
            else{
                if(rounds[i+1]-rounds[i] <= rounds[i]){
                    for(int j = rounds[i]+1; j <= n; j++) frequency[j]++;
                    for(int j = 1; j < rounds[i+1]; j++) frequency[j]++;
                }
            }
        }

        frequency[rounds.back()]++;
        
        for(int i = 1; i < frequency.size(); i++){
            cout << i << " -> " << frequency[i] << endl;   
        }
        
        int maxVisited = 0; 
        for(auto& f: frequency) maxVisited = max(f, maxVisited);

        vector<int> ans;
        for(int i = 1; i < frequency.size(); i++){
            if(maxVisited == frequency[i]) ans.push_back(i);
        }

        return ans;
    }
};