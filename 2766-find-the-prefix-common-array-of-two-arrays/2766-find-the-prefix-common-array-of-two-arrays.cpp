/*
    Input: A = [1,3,2,4], B = [3,1,2,4]
    Output: [0,2,3,4]

    [1,3,2,4]
    [3,1,2,4]

    Input: A = [2,3,1], B = [3,1,2]
    Output: [0,1,3]

    [2,3,1]
    [3,1,2]

    mapA[A[i]]++;
    mapB[B[i]]++;

    if(A[i] != B[i]){
        if(mapA[A[i]] == mapB[A[i]]) curCount++;
        if(mapB[B[i]] == mapA[B[i]]) curCount++;
    }
    else{
        if(mapA[A[i]] == mapB[A[i]]) curCount++;
    }

    totalCount += curConunt;

    mapA        mapB
    1 -> 1      3 -> 1
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mapA, mapB;

        vector<int> ans;
        int n = A.size(), totalCount = 0;
        for(int i = 0; i < n; i++){
            mapA[A[i]]++;
            mapB[B[i]]++;

            int curCount = 0;
            if(A[i] != B[i]){
                if(mapA[A[i]] == mapB[A[i]]) curCount++;
                if(mapB[B[i]] == mapA[B[i]]) curCount++;
            }
            else{
                if(mapA[A[i]] == mapB[A[i]]) curCount++;
            }

            totalCount += curCount;
            ans.push_back(totalCount);
        }

        return ans;
    }
};