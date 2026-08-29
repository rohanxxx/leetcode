/*
    return an arr of len n, where answer[i] is the total number of seats 
    reserved for each flight i

    bookings[i] = [firsti, lasti(inclusive), seatsi]
    Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
    Output: [10,55,45,25,25]

     10. 20  
    1 - 2 - 3
        \ 25
         5
    1 -> 10 
    2 -> 10 + 20 + 25 -> 55
    3 -> 20
    5 -> 25

        1   2   3.  4. 5
    -10    10. 
       -20      20.
       -25            25
        10 55  45 25  
        
*/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int m = bookings.size();
        vector<int> ans(n+1, 0);
        for(int i = 0; i < m; i++){
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seats = bookings[i][2];

            ans[first-1] -= seats;
            ans[last] += seats;
        }

        for(int i = n-1; i >= 0; i--){
            ans[i] += ans[i+1];
        }

        return vector<int>(ans.begin()+1, ans.end());
    }
};