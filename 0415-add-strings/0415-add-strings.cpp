/*
    456 -> 654
     77 -> 77
           335
           533

    123 -> 321
    11  -> 11
           431 -> 134
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        //O(N+K)
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string ans = "";
        int carry = 0, i;
        int n1, n2, add, pop;
        for(i = 0; i < min(num1.size(), num2.size()); i++){
            n1 = num1[i]-'0';
            n2 = num2[i]-'0';
            add = n1 + n2 + carry;
            
            pop = add % 10;
            char c = '0'+pop;
            ans.push_back(c);

            //update the carry
            carry = add / 10;
        }

        while(i < num1.size()){
            n1 = num1[i]-'0';
            add = n1 + carry;
            pop = add % 10;
            char c = '0'+pop;
            ans.push_back(c);

            //update the carry
            carry = add / 10;
            i++;
        }
        while(i < num2.size()){
            n2 = num2[i]-'0';
            add = n2 + carry;
            pop = add % 10;
            char c = '0'+pop;
            ans.push_back(c);

            //update the carry
            carry = add / 10;
            i++;
        }
        if(carry) ans.push_back('0'+carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};