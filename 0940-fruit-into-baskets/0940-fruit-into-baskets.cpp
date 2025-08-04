class Solution {
public:
    /*
         0 1 2 3 4 5 6 7 8
        [1,0,1,4,1,4,1,2,3]
    */
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), count = 0, maxPick = 0;
        //SC: O(3)
        //{key, index}
        unordered_map<int, int> fruitMap;

        //TC: O(3*N)
        for(int i = 0; i < n; i++){
            count++;
            fruitMap[fruits[i]] = i;
            if(fruitMap.size() == 3){
                //reset it here
                int prevPick = fruits[i-1];
                int curPick = fruits[i];
                //TC: O(3)
                for(auto it: fruitMap){
                    if(it.first == prevPick || it.first == curPick) continue;
                    //before you erase update the count
                    count = i-(fruitMap[it.first]);
                    //erase the fruitMap that is not consecutive
                    //O(1)
                    fruitMap.erase(it.first);
                    break;
                }
            }
            //O(1)
            maxPick = max(maxPick, count);
        }

        return maxPick;
    }
};