class Solution {
public:
    bool hasMatch(string s, string p) {
        int t = 0;
        for(int i = 0; i < p.length(); i++){
            if(p[i] == '*'){
                t = i;
                break;
            }
        }

        string left = p.substr(0, t);
        string right = p.substr(t+1);

        cout << "left: " << left << endl;
        cout << "right: " << right << endl;
        bool leftMatched = false;
        bool rightMatched = false;
        
        int ptr = 0;

        // check for leftside first;
        if(left.length() > 0){
            for(; ptr < s.length(); ptr++){
                if(s.substr(ptr, t) == left){
                    leftMatched = true; ptr = ptr+t;
                    break;
                }
            }
        }
        else{
            leftMatched = true;
        }

        /*if(leftMatched == false){
            return false;
        }*/

        cout << "ptr: " << ptr << endl;
        cout << "s[ptr]: " << s[(int)ptr] << endl;

        if(right.length() > 0){
            for(; ptr < s.length(); ptr++){
                if((ptr+ ((int)right.length()-1)) < s.length()){
                    if(s.substr(ptr, (int)right.length()) == right){
                        rightMatched = true;
                    }
                }
            }
        }
        else{
            rightMatched = true;
        }
        
        return leftMatched && rightMatched;
    }
};