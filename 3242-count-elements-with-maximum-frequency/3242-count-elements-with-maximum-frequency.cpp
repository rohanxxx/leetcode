/*

*/
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for(auto& n: nums){
            maxFreq = max(maxFreq, ++freq[n]);
        }
        //cout << "maxFreq: " << maxFreq << endl;
        unordered_set<int> set;
        for(auto& n: nums){
            if(freq[n] == maxFreq){
                set.insert(n);
            }
        }



        return (int)set.size()*maxFreq;
    }
};