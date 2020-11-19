class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>m,aux;
        for(int i=0;i<words.size();i++)
        {
                m[words[i]]++;
        }
        aux=m;
        int num=words[0].length();   //you have to skip this much i, if it matches
        int count=words.size(); //total number of words that should match!
        vector<int>ans;
        if(num*count>s.length()) return ans;
        for(int i=0;i<s.length()-num*count+1;i++)
        {
            if(aux.find(s.substr(i,num))!=aux.end()) 
            {
                aux[s.substr(i,num)]--;
                int rep=1;
                int j=i+num;
                while(1)
                {
                    if(aux[s.substr(j,num)]>0)
                    {
                        rep++;
                        aux[s.substr(j,num)]--;
                    }
                    else break;
                    j=j+num;
                }
                if(rep==count) 
                {
                    ans.push_back(i);
                }
                aux=m;
            }
        }
        return ans;
    }
};