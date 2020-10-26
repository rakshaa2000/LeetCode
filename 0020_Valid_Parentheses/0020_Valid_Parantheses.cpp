class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0) return true;
        if (s.length() == 1) return false;            
        
        stack <char> st;
		/*
		 * Populating a hash set with the pairs makes it easier for pair checks
		*/
        unordered_map <char, char> m = {
            {')', '('},
            {']', '['},
            {'}', '{'},            
        };
        
        for (auto c: s) {
            if (st.empty()) {
                //is a closing par
                if (m.find(c) != m.end()) {
                    return false;
                }
                st.push(c);
            }
            else {
                /*
				last element is a open par, we don't care about last elements being }, 
				since it is a case that will never occur because we always pop on pair matches
				*/
                if (m.find(st.top()) == m.end()) {
                    //c is any open                     
                    if (m.find(c) == m.end()) {
                        st.push(c);
                    }
                    //c is a closing match 
                    else if(m[c] == st.top()) {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
            }            
        }        
        return st.empty();
    }
};