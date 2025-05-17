/*
                      0     1       2       3       4
    Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
    Output: ["/a","/c/d","/c/f"]

    a -> b 
    c -> d -> e
    c -> f

    "/a" -> "/b"
    "/c/d"
    "/c/f"
    
    ["/a/b/c","/a/b/c/d","/a/b/c/d/e"]
    map[/a/b/c] = true;
    map[/a/b/d] = true;
    map[/a/b/ca] = true;

*/
class Solution {
public:
    //TC: O(NlogN + N*L)
    //SC: 
    vector<string> removeSubfolders(vector<string>& folder) {
        //sort()?
        //O(NlogN)
        sort(folder.begin(), folder.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        //for loop to check each indices if they exist or not
        //if the folder never exists then put in the map
        //otherwise if it exists then delete the subfolders
        int n = folder.size();
        //SC: O(N+N)
        unordered_set<string> tempAns;          //to avoid duplicate strings
        unordered_map<string, bool> isFolder;   //to keep track of the prefix folder
        //TC: O(N*max(String Length))
        for(int i = 0; i < n; i++){
            bool isBreak = false;    //use this flag to find out whether it is root folder or not
            stringstream ss(folder[i]);
            string tempStr = "";
            string token = "";
            while(getline(ss, token, '/')){
                if(token.size() == 0){
                    continue;
                }
                tempStr += ("/");
                tempStr += token;
                if(isFolder.count(tempStr) == true){
                    isBreak = true;
                    break;
                }
            }
            //mark is folder
            if(isBreak == false){
                isFolder[tempStr] = true;
                tempAns.insert(tempStr);
            }
        }

        //TC: O(N)
        return vector<string>(tempAns.begin(), tempAns.end());
    }
};