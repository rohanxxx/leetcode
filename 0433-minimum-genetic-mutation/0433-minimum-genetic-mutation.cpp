class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene) return 0;

        unordered_set<char> choices;
        
        choices.insert('A');
        choices.insert('C');
        choices.insert('G');
        choices.insert('T');

        //TC: O(N)
        //SC: O(N)
        unordered_set<string> dict(bank.begin(), bank.end());

        queue<string> q; q.push(startGene);
        
        if(dict.find(startGene) != dict.end()) dict.erase(startGene);

        int count = 0;
        //TC: 32Nlog(4)
        while(!q.empty()){
            int qSize = q.size();
            //TC: O(Level*8*4log(4))
            for(int i = 0; i < qSize; i++){
                string curGene = q.front(); q.pop();
                if(curGene == endGene) return count;
                //TC: O(8*4log(4))
                for(int i = 0; i < curGene.size(); i++){
                    char c = curGene[i];
                    for(auto& it: choices){
                        curGene[i] = it;
                        //found in bank means valid mutation
                        if(dict.find(curGene) != dict.end()){
                            q.push(curGene);
                            dict.erase(curGene);
                        }
                    }
                    curGene[i] = c;
                }
            }
            count++;
        }

        return -1;
    }
};