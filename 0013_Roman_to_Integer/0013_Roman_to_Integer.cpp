class Solution {
public:
    
    int pri(char ch){
        switch(ch){
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
        }
        return -1;
    }
    
    int romanToInt(string s) {
     int n = s.length();
        int res = pri(s[n-1]);
        int pr = res;
        for(int i  = n-2;i>-1;i--){
            if(pri(s[i])>=pr) 
            {
                pr = pri(s[i]);
                res += pr;
            } 
            else
            {
                pr = pri(s[i]);
                res -= pr;
            }
        }
        return res;
    }
};
