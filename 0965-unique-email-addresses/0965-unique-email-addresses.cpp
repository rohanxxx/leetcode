class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        int count = 0;
        string emailAddress = "";
        unordered_map<string, int>umap;
        
        for (int i = 0; i < emails.size(); i++){
            string localName = "";
            string domainName = "";
            
            for(int j = 0; j < emails[i].size(); j++){
                if(emails[i][j] == '.' || emails[i][j] == '+' || emails[i][j] == '@'){
                    if(emails[i][j] == '+' || emails[i][j] == '@'){
                        break;
                    }
                }
                else{
                    localName += emails[i][j];
                }
            }
            // cout << emails[i].substr(1,3) << endl;
            for(int j = emails[i].size()-1; j > 0; j--){
                domainName += emails[i][j];
                if(emails[i][j] == '@'){
                    reverse(domainName.begin(), domainName.end());
                    break;
                }
            }
            
            emailAddress = localName + domainName;
            // cout << "email Address: " << emailAddress << endl;
            
            if(umap[emailAddress] == 0){
                umap[emailAddress]++;
                count++;
            }   
        }
        
        return count;
    }
};