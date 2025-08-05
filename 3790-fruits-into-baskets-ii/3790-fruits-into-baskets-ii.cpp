/*
    Input: fruits = [4,2,5], baskets = [3,5,4]
    Output: 1
              0 1 2
    fruits  = 4 2 5
    baskets = 3 5 4
*/
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        unordered_map<int, int> seen;

        int n = fruits.size(), count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(fruits[i] <= baskets[j]){
                    count++;
                    baskets[j] = 0;
                    break;
                }
            }
        }
        return n-count;
    }
};