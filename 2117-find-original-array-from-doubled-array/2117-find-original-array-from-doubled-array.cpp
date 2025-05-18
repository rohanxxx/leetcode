/*
    original array is transformed to double array changed by appending 2 times
    then shuffled randomly (changed array)

    given changed(n)
    return original array if changed is doubled?

    if not double then return an empty array

    the elements in the original may be returned in any order
                      0 1 2 3 4 5
    Input: changed = [1,3,4,2,6,10]
    Output: [1,3,4]

     0 1 2 3 4 5    5/2 = 2
    {1 2 3 4 6 8}
    map[changed[i]*2]
    map[1*2] = 1 = 0
    map[3*2] = 1 = 0
    map[4*2] = 1 = 0
*/class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // It can't be doubled array, if the size is odd
        if (changed.size() % 2) {
            return {};
        }
        
        // Sort in ascending order
        sort(changed.begin(), changed.end());
        unordered_map<int, int> freq;
        // Store the frequency in the map
        for (int num : changed) {
            freq[num]++;
        }
        
        vector<int> original;
        for (int num : changed) {
            // If element exists
            if (freq[num]) {
				freq[num]--;
                int twiceNum = num * 2;
                if (freq[twiceNum] > 0) {
                    // Pair up the elements, decrement the count
                    freq[twiceNum]--;
                    // Add the original number to answer
                    original.push_back(num);
                } else {
                    return {};
                }
            }
        }
        
        return original;
    }
};