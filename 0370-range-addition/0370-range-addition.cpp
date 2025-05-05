class Solution {
public:
/*
    length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
    Output: [-2,0,3,5,3]

    -2 0 3 5 2
     0 1 2 3 4

                    nums[i] = nums[i-1] + nums[i]
     0 1 2 3 4 
     
    -2 2 5 -2 -3  
     0 1 2  3  4
    -2 0 7
*/
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);

    for (auto& tuple : updates) {
        int start = tuple[0], end = tuple[1], val = tuple[2];

        result[start] += val;
        if (end < length - 1)
            result[end + 1] -= val;
    }

    /*for(int i = 0; i < length; i++){
        cout << result[i] << " ";
    }
    cout << endl;*/
    // partial_sum applies the following operation (by default) for the parameters {x[0], x[n], y[0]}:
    // y[0] = x[0]
    // y[1] = y[0] + x[1]
    // y[2] = y[1] + x[2]
    // ...  ...  ...
    // y[n] = y[n-1] + x[n]

    partial_sum(result.begin(), result.end(), result.begin());

    return result;
    }
};