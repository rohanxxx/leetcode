/*
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
*/
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        // 1# get the roots alongside with the content and map it based on the content
        unordered_map<string, vector<string>> map; 
        for(string path: paths){
            stringstream ss(path);
            string word = "";

            ss >> word;

            string directory = word;

            while(ss >> word){
                //gets the file
                string fileName = "", content = "";
                stringstream fs(word);
                
                getline(fs, fileName, '(');
                getline(fs, content, ')');

                string fullDirectory = directory + "/" + fileName;

                map[content].push_back(fullDirectory);
            }
        }

        vector<vector<string>> ans;
        // 2# retrieve from the content
        for(auto it: map){
            string content = it.first;
            if(map[content].size()> 1){
                ans.push_back(it.second);
            }
        }

        return ans;
    }
};