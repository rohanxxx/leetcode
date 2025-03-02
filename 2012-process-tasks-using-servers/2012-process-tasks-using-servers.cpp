class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int>v;
       
        int n=servers.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue<pair< int,pair<int, int>>, vector<pair< int,pair<int, int>>>, greater<pair< int,pair<int, int>>>> p;
        
        for(int i=0;i<n;i++){
            pq.push({servers[i],i});
        }
        
        int m = tasks.size();
        int s = 0;
        for(int i = 0; i < m; i++){
            s = max(s,i);
            while(!p.empty() && p.top().first <= s){
                pq.push({p.top().second.first,p.top().second.second});
                p.pop();
            }
            if(pq.empty()){
                s=p.top().first;
                while(!p.empty()&& p.top().first<=s){
                    pq.push({p.top().second.first,p.top().second.second});
                    p.pop();
                }
            } 
            v.push_back(pq.top().second);
            p.push({s+tasks[i],{pq.top().first,pq.top().second}});
            pq.pop();
            if(v.size()==m)break;
        }
        return v;
    }
};