/*
    n = 1
      0 1
    0 0 0
    1 0 0
    mid = size/2 = 1
    when
    3rd quadrant 
    row 0 to mid & col mid to size
    4th quad 
    row mid to end & col mid to end
    2nd quadrant
    row from mid to row < size & col is from 0 to less than size
    1st quadrant 
    row < mid & col < mid

    n = 2
    4 * 4
    0 0 0 0
    0 0 0 0
    0 0 0 0
    0 0 0 0

    n = 3
    
        0 1 2 3 4 5 6 7 
    0
    1
    2
    3
    4
    5
    6
    7
*/
class Solution {
public:
    void helper(vector<vector<int>>& v, int rs, int re, int cs, int ce, int& n) {
        if (rs == re && cs == ce) {
            v[rs][cs] = n--;
            return;
        }

        int mr = (rs + re) / 2;
        int mc = (cs + ce) / 2;

       
        helper(v, rs, mr, cs, mc, n);           
        helper(v, mr + 1, re, cs, mc, n);      
        helper(v, mr + 1, re, mc + 1, ce, n);  
        helper(v, rs, mr, mc + 1, ce, n);       
    }

    vector<vector<int>> specialGrid(int N) {
        if (N == 0) return {{0}};

        int size = pow(2,N);
        int n = pow(4,N) - 1;
        vector<vector<int>> res(size, vector<int>(size));
        helper(res, 0, size - 1, 0, size - 1, n);
        return res;
    }
};