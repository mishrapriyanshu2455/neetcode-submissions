class Solution {
public:

    int f(int stair,vector<int>&dp)
    {
        if (stair==0) return 1;
        if (stair<0) return 0;

        if (dp[stair] != -1)
        return dp[stair];

        return dp[stair]=f(stair-1,dp)+f(stair-2,dp);
    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};
