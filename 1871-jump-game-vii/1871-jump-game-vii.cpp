/*.      0 1 2 3 4 5 6 7
    s = "0 1 1 0 1 1 1 0", minJump = 2, maxJump = 3
*/
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.length();

        queue<int> q;
        q.push(0);

        vector<bool> visited(n, false);
        visited[0] = true;

        int farthest = 0;

        while(!q.empty()){

            int index = q.front();
            q.pop();

            if(index == n - 1){
                return true;
            }

            int start = max(index + minJump, farthest + 1);
            int end = min(index + maxJump, n - 1);

            for(int i = start; i <= end; i++){

                if(s[i] == '0' && !visited[i]){

                    visited[i] = true;
                    q.push(i);
                }
            }

            farthest = end;
        }

        return false;
    }
};