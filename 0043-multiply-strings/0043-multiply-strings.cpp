class Solution {
public:
    string multiply(string num1, string num2) {
        
        if (num1[0] == '0' || num2[0] == '0') return "0";
       
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int size = num1.size()+num2.size();
        
        string newStr(size, '0');
        //int place = 0;
        for(int i = 0; i < num2.size(); i++){
            int digit1 = num2[i] - '0';
            for(int j = 0; j < num1.size(); j++){
                
                int digit2 = num1[j] - '0';
                
                int newStr_index = i+j;
            
                int carry = newStr[newStr_index] - '0';
                int multiply = digit1*digit2 + carry;
               
                //assigning the newStr here
                newStr[newStr_index] = '0'+multiply%10;
                
                //calculates the carry bit happens here
                //next index is always zero therefore we don't have to do '0'+int_value
                newStr[newStr_index + 1] += (multiply / 10);
                
            }
            //place++;
        }
        
        if(newStr.back() == '0'){
            newStr.pop_back();
        }
        
        reverse(newStr.begin(), newStr.end());
        
        return newStr;
    }
};