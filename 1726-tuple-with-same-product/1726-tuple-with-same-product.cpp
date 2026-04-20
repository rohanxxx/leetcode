/*
    return the number of tuples with distinct positive integers
    a*b == c*d
    a != b b != c c!= d
    key Note: all elements are distinct

    nums = [2,3,4,6]
    2*3 -> 6 
    2*4 -> 8
    2*6 -> 12
    3*4 -> 12
    3*6 -> 18
    4*6 -> 24
    
    6 -> {2,3}
    8 -> {2,4}
    12 -> {2,4,3,6}
    24 -> {4,6}

    {2,4,3,6}

    2,4,3,6 -> 2,4,6,3 -> 4,2,3,6 -> 4,2,6,3
    2,4 -> 3,6
    2,4 -> 6,3

    2*((4-2)*(4/2)) -> 2*2*2 -> 8

    [1,2,4,5,10]
    2*10 -> 20
    4*5 -> 20
    4*10 -> 40
    5*10 -> 50

    10 -> 4
    20 -> 4

    2^3-1 -> 8 + 2^3-1 -> 8

    4*5 -> 20
    10*2 -> 20

    {3,10},{5,6},{15,2}

    3,10->5,6
    3,10->6,5
    3,10-> 2,15
    3,10-> 15,2

    10,3

    4*2 -> 8
    2*(6-2)*(6/2)
*/
class Solution {
public:
    //TC: O(N*N)
    //SC: O(M)
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long, int> map;
        int n = nums.size();
        //TC: O(N*(N-1))
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                long long product = (long long)nums[i]*nums[j];
                map[product] += 2;
            }
        }

        int res = 0;
        for(auto it: map){
            int y = it.second;
            res += (2 * (y-2) * (y/2));
        }

        return res;
    }
};