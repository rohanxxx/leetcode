class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int p1 = 0, p2 =0;
        int size1 = slots1.size(), size2 = slots2.size();
        
        while(p1 < size1 && p2 < size2){
            int rightBound = min(slots1[p1][1], slots2[p2][1]);
            int leftBound = max(slots1[p1][0], slots2[p2][0]);

            // cout << "leftBound: " << leftBound << ", rightBound: " << rightBound << endl;
            if(rightBound - leftBound >= duration) return {leftBound, leftBound+duration};

            if(slots1[p1][1] < slots2[p2][1]) p1++;
            else p2++;
        }

        return {};
    }
};