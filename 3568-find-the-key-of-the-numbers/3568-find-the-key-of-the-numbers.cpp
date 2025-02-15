class Solution {
public:
    void fill(deque<int>& n, int num){
        while(num){
            int pop = num % 10;
            n.push_front(pop);
            num = num/10;
        }

        if(n.size() > 4){
            while(n.size() > 4){
                n.pop_back();
            }
        }
        else{
            while(n.size() < 4){
                n.push_front(0);
            }
        }

        return;
    }

    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        deque<int> n1, n2, n3, dq;
        
        fill(n1, num1);
        fill(n2, num2);
        fill(n3, num3);

        for(int i = 0; i < 4; i++){
            dq.push_back(min({n1.front(), n2.front(), n3.front()}));
            n1.pop_front(); n2.pop_front(); n3.pop_front();
        }

        int key = 0;
        while(!dq.empty()){
            key = key * 10;
            key = key + dq.front();
            dq.pop_front();
        }

        return key;
    }
};