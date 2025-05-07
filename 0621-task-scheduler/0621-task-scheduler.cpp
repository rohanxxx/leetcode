class Solution {
public:
/*
    CPU can be idle or allow the completion of one task
    Task can be completed in any order
    contraint -> has to have a gap of n intervals
    return minimum number of CPU intervals to complete all tasks

    A A A B B B n = 2
    A B IDLE A B IDLE A B
    
    A C A B D B n = 1
    A B C D A B
*/
    int leastInterval(vector<char>& tasks, int n) {
        // Building frequency map
        int freq[26] = {0};
        for (char &ch : tasks) {
            freq[ch - 'A']++;
        }

        // Max heap to store frequencies
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;
        // Process tasks until the heap is empty
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> store;
            int taskCount = 0;
            // Execute tasks in each cycle
            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1) {
                    store.push_back(pq.top() - 1);
                }
                pq.pop();
                taskCount++;
            }
            // Restore updated frequencies to the heap
            for (int &x : store) {
                pq.push(x);
            }
            
            if (pq.empty()) {
                time += taskCount;
            } else {
                time += n + 1;
            }
        }
        return time;
    }
};