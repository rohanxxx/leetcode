class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b){
        if(a.first < b.first) return true;
        if(a.first > b.first) return false;
        //in the case when a.first == b.first 
        //we go with the fastest speed one
        return b.second >= a.second;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> cars;
        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), comp);
        
        //double t = 0.0;
        stack<double> stack;

        for(int i = n-1; i >= 0; i--){
            double t = (double)(target-cars[i].first)/(double)cars[i].second;
            if(!(!stack.empty() && stack.top() >= t)){
                stack.push(t);
            }
        }

        return (int)stack.size();
    }
};