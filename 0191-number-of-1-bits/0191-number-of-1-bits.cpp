class Solution {
public:
/*          8 4 2 1
    11->    1 0 1 0
            1
*/
    int hammingWeight(int n) {
        int count = 0;
        for(int i = 0; i < 32; i++){
            if(n & (1 << i)){
                count++;
            }
        }
        return count;   
    }
};