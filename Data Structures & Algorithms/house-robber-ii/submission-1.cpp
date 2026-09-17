class Solution {
public:
    int f(vector<int>& nums,int start,int end)
    {
        int next1=nums[end];
        int next2=0;
        int current=0;

        for(int i=end-1;i>=start;i--)
        {
            current=max(nums[i]+next2,next1);
            next2=next1;
            next1=current;
        }

        return next1;
    }


    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1)
            return nums[0];
       
        int case1=f(nums,0,n-2);
        int case2=f(nums,1,n-1);

        return max(case1,case2);

    }
};
