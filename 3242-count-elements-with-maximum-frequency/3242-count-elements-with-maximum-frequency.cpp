/*

*/
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0, count = 0;
        for(auto& n: nums){
            maxFreq = max(maxFreq, ++freq[n]);
        }
    
        for(auto it: freq){
            if(freq[it.first] == maxFreq){
                count++;
            }
        }

        return count * maxFreq;
    }
};