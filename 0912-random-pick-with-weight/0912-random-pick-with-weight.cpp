class Solution {
private:
    vector<int> prefixSum;
public:
    Solution(vector<int>& w) {
        for(auto& n: w){
            if(prefixSum.empty()){
                prefixSum.push_back(n);
                continue;
            }
            prefixSum.push_back(n+prefixSum.back());
        }
    }
    
    int pickIndex() {
        float randomNum = (float) rand() / RAND_MAX;
        float targetNum = randomNum * prefixSum.back();
        for(int i = 0; i < prefixSum.size(); i++){
            if(targetNum < prefixSum[i]) return i;
        }

        return prefixSum.size()-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */