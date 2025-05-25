class Solution {
public:
    string sortSentence(string s) {
        vector<string> stringMap(9);
        stringstream ss(s);
        string word;

        while(ss >> word){
            int index = word.back()-'0';
            //cout << "index: " << index << endl;
            word.pop_back();
            //cout << "word: " << word << endl << endl;
            stringMap[index-1] = word;
        }

        string ans = "";
        //O(9)
        for(int i = 0; i < 9; i++){
            if(stringMap[i].size() == 0){
                break;
            }
            ans += stringMap[i];
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};