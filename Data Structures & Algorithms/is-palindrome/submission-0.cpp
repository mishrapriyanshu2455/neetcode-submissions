class Solution {
public:

    bool isAlphaNum(char ch)
    {
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z') ||
               (ch >= '0' && ch <= '9');
    }

    char toLower(char ch)
    {
        if (ch >= 'A' && ch <= 'Z')
            return ch + 32;

        return ch;
    }

    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            while (left < right && !isAlphaNum(s[left]))
                left++;

            while (left < right && !isAlphaNum(s[right]))
                right--;

            if (toLower(s[left]) != toLower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};