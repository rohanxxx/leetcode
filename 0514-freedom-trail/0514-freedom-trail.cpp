/*
    quest requires players to reach a metal dial and use the dial to spell a specific keyword to open the door
    given a string represents the code engraved on the outer ring 
    and another string key that represents the keyword that needs to be spelled 
    return the minimum number of steps to spell all the characters in the keyword

    - intially the first character of the ring is aligned at the 12:00 direction
    - u should spell all the characters in the key one by one rotating ring clockwise or anticlockwise
    - to make each character of the string aligned at the 12:00 direction and then pressing the center button

    Input: ring = "godding", key = "gd"

                                12 
                            11        1 
                        10                2
                    9                        3
                        8                4
                            7        5
                                6    

                                g 
                            d       o
                        n                d
                            i        d

                            key = gd
                    our 12:00 is the node 0 is our first target
       ring:        g o d d i n g
                    0 1 2 3 4 5 6

                1 - 0 - 6 -
                |           |
                2 - 3 - 4 - 5

                our first target is 0

                we would will build an undirected graph
                then we will store the indexes of each characters node number aka (index) in an unordered map

*/

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringLen = ring.length();
        int keyLen = key.length();
        
        // HashMap to store the indices of occurrences of each character in the ring
        unordered_map<char, vector<int>> characterIndices;
        for (int i = 0; i < ring.length(); i++) {
            char ch = ring[i];
            characterIndices[ch].push_back(i);
        }

        // Initialize the heap (priority queue) with the starting point
        // Each element of the heap is a vector of integers representing:
        // totalSteps, ringIndex, keyIndex
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        heap.push({0, 0, 0});

        // HashSet to keep track of visited states
        unordered_set<string> seen;
        
        // Spell the keyword using the metal dial
        int totalSteps = 0;
        while (!heap.empty()) {
            // Pop the element with the smallest total steps from the heap
            vector<int> state = heap.top();
            heap.pop();
            totalSteps = state[0];
            int ringIndex = state[1];
            int keyIndex = state[2];
            
            // We have spelled the keyword
            if (keyIndex == keyLen) {
                break;
            }
            
            // Continue if we have visited this character from this position in ring before
            string currentState = to_string(ringIndex) + "-" + to_string(keyIndex);
            if (seen.count(currentState)) {
                continue;
            }

            // Otherwise, add this pair to the visited list
            seen.insert(currentState);
            
            // Add the rest of the occurrences of this character in ring to the heap
            for (int nextIndex : characterIndices[key[keyIndex]]) {
                heap.push({totalSteps + countSteps(ringIndex, nextIndex, ringLen), nextIndex, keyIndex + 1});
            }
        }
        
        // Return the total steps and add keyLen to account for 
        // pressing the center button for each character in the keyword
        return totalSteps + keyLen;
    }

private:
    // Find the minimum steps between two indexes of ring
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }
};