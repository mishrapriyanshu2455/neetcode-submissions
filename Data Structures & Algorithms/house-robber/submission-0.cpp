class Solution {
public:
    int f(int ind,vector<int>& nums,vector<int>&dp)
    {
        if(ind==nums.size()-1) return nums[nums.size()-1];
        if(ind>nums.size()-1)  return 0;

        if(dp[ind]!=-1) return dp[ind];

        return dp[ind]=max(nums[ind]+f(ind+2,nums,dp),0+f(ind+1,nums,dp));
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+2,0);
        int n=nums.size()-1;

        dp[n]=nums[n];
        dp[n+1]=0;
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=max(nums[i]+dp[i+2],0+dp[i+1]);
        }

        return max(dp[0],dp[1]);
    }
};
