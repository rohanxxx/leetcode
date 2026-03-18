class Solution {
public:
    static bool comp(string& a, string& b){
        if(a+b > b+a) return true;
        return false;
    }
    string largestNumber(vector<int> &nums) {
        vector<string> numStrings;
        // Convert each integer to a string
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }

        // Sort strings based on concatenated values
        sort(numStrings.begin(), numStrings.end(), comp);

        /*for(int i = 0; i < numStrings.size(); i++){
            cout << numStrings[i] << " ";
        }
        cout << endl;*/

        // Handle the case where the largest number is zero
        if (numStrings[0] == "0") return "0";

        // Concatenate sorted strings to form the largest number
        string largestNum;
        for (string &numStr : numStrings) {
            largestNum += numStr;
        }

        return largestNum;
    }
};