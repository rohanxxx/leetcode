class Solution {
public:
    struct compare{
        bool operator() (const int &a, const int &b){
            return a > b;
        }
    };
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        //sorts the intervals
        sort(intervals.begin(), intervals.end());
        
        //create the custom class minQue
        priority_queue<int, vector<int>, compare> minQue;
        
        for(int i = 0; i < intervals.size(); i++){
            if(!minQue.empty()){ 
                if(minQue.top() <= intervals[i][0]){
                    minQue.pop();
                }
            }
            minQue.push(intervals[i][1]);
        }
        /*
        for(int i = 0; i < minQue.size(); i++){
            cout << minQue.top() << " ";
            minQue.pop();
        }

        cout << minQue.top() << " ";

        cout << endl;
        */
        return minQue.size();
    }
};