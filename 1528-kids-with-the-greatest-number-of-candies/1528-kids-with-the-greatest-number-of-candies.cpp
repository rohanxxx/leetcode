class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //first find the max candie that a kid has currently
        int n = candies.size();
        int maxCandie = INT_MIN;
        //O(N)
        for(int i = 0; i < n; i++){
            maxCandie = max(maxCandie, candies[i]);
        }
        //cout << "maxCandie: " << maxCandie << endl; 
        //then add extraCandies with each kid and compare with candie to return the bool
        //O(N)
        vector<bool> ans(n, false);
        //O(N)
        for(int i = 0; i < n; i++){
            //cout << "i: " << i << endl;
            //cout << "candies[i]+extraCandies: " << candies[i]+extraCandies << endl;
            if(candies[i]+extraCandies >= maxCandie) ans[i] = true;
        }

        return ans;
    }
};