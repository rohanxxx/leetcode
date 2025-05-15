/*
    len at least 2 for subsequence
    after sorting the subseq each element except the first element is the square of the prev number

    return the length of the longest sqaure streak

            0 1 2  3 4 5
    nums = [4,3,6,16,8,2] -> [4, 16, 2] -> [2, 4, 16] 
    Output: 3

    2^2 = 4
    for(i->n)
    maxStreak = max(map[2], maxStreak);
    long long curElementSq;
    map[curElement]++;
*/
class Solution {
public:
    //TC:O(n+nlogn)
    //SC:O(N)
    int longestSquareStreak(vector<int>& nums) {
        //declare the hashmap
        //SC: O(1)
        int maxStreak = 0;
        //SC: O(N+N)
        unordered_map<long, int> squareMap;
        unordered_map<int, bool> visited;
        
        //sort it out
        //TC: O(nlogn)
        sort(nums.begin(), nums.end());
        //0 1 2 3 4 5
        /*
         2->1
         4->1
         3->1
         4->2
         16->2
        */
        //2,3,4,6,8,16
        int n = nums.size();
        //O(N)
        for(int i = 0; i < n; i++){
            int curElement = nums[i];
            if(visited[curElement] == true){
                continue;
            }
            visited[curElement] = true;
            //TC: O(1)
            squareMap[curElement]++;
            
            //constantly checking for the maxStreak
            //TC: O(1)
            maxStreak = max(maxStreak, squareMap[curElement]);

            //TC: O(1)
            long squareElement = ((long)curElement*curElement); //O(1)
            squareMap[squareElement] += (squareMap[curElement]);
        }

        if(maxStreak == 1) return -1;
        return maxStreak;
    }
};