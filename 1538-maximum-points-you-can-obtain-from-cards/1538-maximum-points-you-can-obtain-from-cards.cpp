class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        vector<int> frontCards(k+1, 0), backCards(k+1, 0);
        for(int i = 0; i < k; i++){
            frontCards[i+1] = frontCards[i]+cardPoints[i];
            backCards[i+1] = backCards[i]+cardPoints[size-1-i];
        }

        int maxPoints = 0;
        for(int i = 0; i <= k; i++){
            int currentScore = frontCards[i]+backCards[k-i];
            maxPoints = max(maxPoints, currentScore);
        }

        return maxPoints;
    }
};