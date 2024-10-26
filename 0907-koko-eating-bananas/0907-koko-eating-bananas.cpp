class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {     
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int middle = (left + right) / 2;
            int hourSpent = 0;

            for (int pile : piles) {
                int quo = pile / middle;
                int rem = pile % middle;
                if(quo > 0){
                    hourSpent += (quo + (rem > 0));
                    if(hourSpent > h) break;
                    continue; 
                }

                hourSpent++;
                if(hourSpent > h) break;
            }

            if (hourSpent <= h) right = middle;
            else left = middle + 1;
        }

        return right;
    }
};
