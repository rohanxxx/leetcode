class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> set (arr.begin(), arr.end());

        int n = arr.size(), res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int prev = arr[i], cur = arr[j], next = prev + cur;
                
                int length = 2;
                while(set.find(next) != set.end()){
                    length++;
                    prev = cur; 
                    cur = next;
                    next = prev + cur; 
                    res = max(res, length);
                }
            }
        }

        return res;
    }
};