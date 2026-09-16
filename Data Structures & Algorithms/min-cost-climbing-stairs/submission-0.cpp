class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int top2=0;
        int top1=0;
        int current=0;
        for(int i=n-1;i>=0;i--)
        {
            current=cost[i]+min(top2,top1);
            top2=top1;
            top1=current;
        }

        return min(top1,top2);
    }
};
