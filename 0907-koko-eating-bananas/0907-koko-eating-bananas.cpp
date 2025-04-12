class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {     
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int middle = (left + right) / 2;
            int hourSpent = 0;

            for (int pile : piles) {
                int curHourSpent = ceil((double)pile/(double)middle);
                if(curHourSpent == 0) curHourSpent = 1;
                hourSpent += curHourSpent;
                if(hourSpent > h) break;
            }

            if (hourSpent <= h) right = middle;
            else left = middle + 1;
        }

        return right;
    }
};
