class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort the events by start time, and if equal, by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
        int day = 0, index = 0, n = events.size(), result = 0;

        while (!pq.empty() || index < n) {
            if (pq.empty()) {
                day = events[index][0];
            }

            // Add all events that start on or before the current day
            while (index < n && events[index][0] <= day) {
                pq.push(events[index][1]); // Push the end day
                index++;
            }

            // Remove all events that have already ended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend the event with the earliest end day
            if (!pq.empty()) {
                pq.pop();
                result++;
                day++;
            }
        }

        return result;   
    }
};