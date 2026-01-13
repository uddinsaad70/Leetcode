class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, res = 0;
        unordered_set<char>st;
        for(;j < s.size();j++){
            while(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            res = max(res, j - i + 1);
        }
        return res;
    }
};