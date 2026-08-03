class Solution {
public:
    bool isAnagram(string s, string t) {
         vector<int>first(26,0);
        vector<int>second(26,0);

        if(s.size()!=t.size()) return false;

        for(int i=0;i<s.size();i++)
        {
            first[s[i]-'a']++;
            second[t[i]-'a']++;
        }

        return first==second;
    }
};
