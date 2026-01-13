class Solution {
public:
    int characterReplacement(string s, int k) {
        int winSize = 0, maxfreq = 0, l = 0, r = 0, ans = 0;
        int Ar[129] = {0};

        for(;r < s.size(); r++){
            winSize = r - l + 1;
            Ar[s[r]]++;
            for(int i = 'A'; i <= 'Z'; i++){
                maxfreq = max(maxfreq, Ar[i]);
            }

            if(winSize - maxfreq > k){
                Ar[s[l]]--;
                l++;
            }
            else{
                ans = max(ans,winSize);
            }
        }
        return ans;
    }
};