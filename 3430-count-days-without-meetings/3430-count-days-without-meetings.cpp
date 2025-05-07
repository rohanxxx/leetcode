/*
    given positive integer days which is the total number of days an employee is available for work,
    starting from day 1;

    also given a meetings[i] = [start_i, end_i] meeting i (inclusive)

    return the count of days when the employee is available for work but no meetings are scheduled

    Note: meetings may overlap

    days that have no meetings 4, 8

    Input: days = 5, meetings = [[2,4],[1,3]] -> [1,3], [2,4]
    Output: 1

     vector<int> (n+1, 0);
     0 1.  1 -1 -1
     0 1 2 3  4 5
     0 1 1 2  1 0
    
    Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
    Output: 2

       1.    -1 1.    -1 1
     0 1 2 3  4 5 6 7  8 9 10
     0 1 1 1. 0 1 1 1  0 1 1

     [[2,3],[1,2],[2,3],[2,4],[1,2],[1,3]] n = 4
       1 1 -1  -1
     0 1 2  3  4
*/
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeDays = 0, latestEnd = 0;

        // Sort meetings based on starting times
        sort(meetings.begin(), meetings.end());

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // Add current range of days without a meeting
            if (start > latestEnd + 1) {
                freeDays += start - latestEnd - 1;
            }

            // Update latest meeting end
            latestEnd = max(latestEnd, end);
        }

        // Add all days after the last day of meetings
        freeDays += days - latestEnd;

        return freeDays;
    }
};