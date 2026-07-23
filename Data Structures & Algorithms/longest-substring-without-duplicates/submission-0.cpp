class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0;
        int len=s.size();
        int ans=0;
        vector<char>alpha(128,0);

        while(end<len)
        {
           while(alpha[s[end]]>0)
           {
                alpha[s[start]]--;
                start++;
           }
           
           alpha[s[end]]++;
           ans=max(ans,end-start+1);
           end++;
        }

           return ans;
    }
};
