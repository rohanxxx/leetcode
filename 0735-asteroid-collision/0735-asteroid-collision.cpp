/*
    3,5,-6,2,-1,4
    3x,5x,-6,2 

    case 1 cur < 0 && 

    [-2,-1,1,2]
    -2,
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto asteroid: asteroids){
            while(!ans.empty() && asteroid < 0 && ans.back() > 0 && ans.back() < abs(asteroid)){
                ans.pop_back();
            }

            if(!ans.empty() && asteroid < 0 && ans.back() > 0 && ans.back() == abs(asteroid)){
                ans.pop_back();
                continue;
            }

            if(!ans.empty() && ans.back() > 0 && asteroid < 0){
                continue;
            }
            
            ans.push_back(asteroid);
            
        }

        return ans;
    }
};