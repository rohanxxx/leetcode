/*
    s = even length string
    split s into a and b equal lengths

    s can contain upper case and lower case letter
    two strings are alike if they have same number of vowels (a e i o u)

    Input: s = "book"
    Output: true    
    
    boo kae
    123 123

    b1235abc
*/

class Solution {
public:
    int countVowels(string& s, int start, int end){
        int counter = 0;
        //first loop counts the first half
        //O(N/2)
        for(int i = start; i < end; i++){
            if(s[i] == 'a' || s[i] == 'A'){
                counter++;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                counter++;
            }
            else if(s[i] == 'i' || s[i] == 'I'){
                counter++;
            }
            else if(s[i] == 'o' || s[i] == 'O'){
                counter++;
            }
            else if(s[i] == 'u' || s[i] == 'U'){
                counter++;
            }
        }
        return counter;
    }
    //O(N/2+N/2) = O(N)
    //O(1)
    bool halvesAreAlike(string s) {
        //get the midpoint
        //run two for loops

        int n = s.length();
        int mid = s.length()/2;
        //it will check first half of the string
        int counter1 = countVowels(s, 0, mid);
        //it will check second half of the string 
        int counter2 = countVowels(s, mid, n);
        //cout << "mid: " << mid << endl;
        //cout << "counter1: " << counter1 << endl;
        //cout << "counter2: " << counter2 << endl;
        //then check first half counter and 2nd half counter if match true otherwise false
        if(counter1 == counter2){
            return true;
        }
        return false;
    }
};