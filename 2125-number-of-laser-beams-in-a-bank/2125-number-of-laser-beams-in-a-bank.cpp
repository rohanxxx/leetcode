class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev_row_laser_count = 0;
        for(auto c: bank[0]){
            if(c == '1'){
                prev_row_laser_count++;
            }
        }

        int n = bank.size();
        int laserBeamCount = 0;
        for(int i = 1; i < n; i++){
            int cur_row_laser_count = 0;
            for(auto c: bank[i]){
                if(c == '1'){
                    cur_row_laser_count++;
                }
            }
            laserBeamCount += (prev_row_laser_count*cur_row_laser_count);
            if(cur_row_laser_count){
                prev_row_laser_count = cur_row_laser_count;
            }
        }

        return laserBeamCount;
    }
};