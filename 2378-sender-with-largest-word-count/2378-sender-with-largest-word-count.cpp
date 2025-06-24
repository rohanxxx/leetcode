class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        //SC: O(N)
        unordered_map<string, int> wordCount;
        //builds the wordCount map

        //TC: O(N*M)
        for(int i = 0; i < n; i++){
            istringstream ss(messages[i]);
            string word = "";
            while(ss >> word){
                wordCount[senders[i]]++;
            }
        }

        int maxCount = INT_MIN;
        string ans = "";
        //TC: O(N)
        for(auto& [sender, count]: wordCount){
            if(maxCount <= count){
                if(maxCount == count){
                    if(ans < sender) ans = sender;
                }
                else{
                    ans = sender;
                }
                maxCount = count;
            }
        }

        return ans;
    }
};

/*
    ["nT","y Mx p iD Lo",
    "xVg Ak IyQ u MG lmS Hq q e mb","N Qf i y",
    "Zrs sbc tKE GGx xM D","wo UEZ uPf Xi XjE",
    "tL y n","ac Up cy znC uw I","Dx vVW qa vxm",
    "spz D MEB pq","ktu buy","Mau Y ob J gqD jVZ B pXS",
    "q dB bdC Zd p dpr Np N","Qqx O umB j iO hM eMW Nt",
    "T Vo C pnD r Dso PP qA q","u s vPx c LeH ju z",
    "W Dee VQG a e"]

    ["dhOKiI",
    "OfOpYKCNku",
    "zyh",
    "hr",
    "o",
    "jDklz",
    "lre",
    "Zpi",
    "doorY","OfOpYKCNku","doorY","b","wjAC","fBsUhoLpG","Zpi","wjAC","Owwx"]
*/