class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int>mp;
       int start=0,end=0,count=0,ans=INT_MAX;
       int index=-1;
       string req="";

       for(int i=0;i<t.size();i++)
       {
        mp[t[i]]++;
        count++;
       }

        while(end<s.size())
        {
            mp[s[end]]--;

            if(mp[s[end]]>=0)
            count--;

            while(!count && start<=end)
            {
                if(ans>end-start+1)
                {
                    ans=end-start+1;
                    index=start;
                }

                mp[s[start]]++;
                if(mp[s[start]]>0) count++;

                start++;
            }

            end++;
        }

        if(index==-1) return req;

        for(int i=index;i<index+ans;i++)
        {
            req+=s[i];
        }

        return req;
    }
};
