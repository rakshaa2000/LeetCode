class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> num;
        for(auto i=nums.begin(); i!=nums.end(); i++){
            num.insert(*i);
        }
        return num.size();
    }
};