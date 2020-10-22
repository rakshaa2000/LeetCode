class Solution {
public:
    int myAtoi(string str) {
        size_t res=0;
        bool is_positive = true;
        int i=0;
        
        while (str[i] == ' ') // count leading spaces
            i++;
        
        if (str[i] == '-') // check sign
        {
            is_positive = false;
            i++;
        }
        else if (str[i] == '+')
        {
            is_positive = true;
            i++;
        }
        str.erase(0,i); // remove leading spaces and sign
        
        for (int i=0;i<str.size();i++)
        {
            if (isdigit(str[i]))
            {
                (res*=10) += str[i] - '0';
                
                if ((res >= (pow(2,31))) && (is_positive))
                    return INT_MAX;
                if ((res > (pow(2,31))) && (!is_positive))
                    return INT_MIN;
            }
            else // no more digits
                break;
        }
        
        if (!is_positive)
            return -res;
        return res;
    }
};
