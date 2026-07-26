class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // Frequency of s1
        for (char ch : s1)
            need[ch - 'a']++;

        // First window
        for (int i = 0; i < s1.size(); i++)
            window[s2[i] - 'a']++;

        if (need == window)
            return true;

        // Slide window
        for (int i = s1.size(); i < s2.size(); i++) {

            window[s2[i] - 'a']++;               // add new char
            window[s2[i - s1.size()] - 'a']--;   // remove old char

            if (need == window)
                return true;
        }

        return false;
    }
};