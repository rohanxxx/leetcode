/*
    A = [1,3,2,4]
    B = [3,1,2,4]
         0 2 3 4

    1 -> 2
    3 -> 2

    count = 0
    A = [2,3,1]
    B = [3,1,2]
         0 1 3

*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();

        if(n != m){
            return {};
        }

        int count = 0;
        vector<int> ans;
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[A[i]]++;
            freq[B[i]]++;

            if(freq[A[i]] == 2){
                count++;
            }

            if(A[i] != B[i] && freq[B[i]] == 2){
                count++;
            }
            ans.push_back(count);
        }

        return ans;
    }
};