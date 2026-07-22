/*
    mass = 10, asteroids = [3,9,19,5,21]
     0 1 2. 3.4
    [3,9,19,5,21]

    3,5,9,19,21
    13, 18, 27, 46,67

    4, 4, 9, 23

    5, 9, 13, 22
*/
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        
        long long curMass = mass;
        for(int i: asteroids){
            if(curMass >= i){
                curMass = (long long)curMass + i;
            }
            else{
                return false;
            }
        }

        return true;
    }
};