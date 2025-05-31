/*
    Input: people = [3,2,2,1], limit = 3
    Output: 3

    2,1
    2,
    3

    1 2 2 3

    Input: people = [3,5,3,4], limit = 5
    Output: 4

    3 3 4 5 limit 5

*/
class Solution {
public:
    //TC: O(NlogN + N) = O(NLogN)
    //SC: O(logN) due to sorting algorithm worse case scenario
    int numRescueBoats(vector<int>& people, int limit) {
        int boatCount = 0;
        //TC: O(NlogN)
        sort(people.begin(), people.end());
        int left = 0, right = people.size()-1;
        //TC: O(N)
        while(left <= right){
            int w = people[left] + people[right];
            if(w <= limit){
                left++;
                right--;
            }
            else{
                right--;
            } 
            boatCount++;
        }
        return boatCount;
    }
};