class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int area=0;
        int start=0,end=heights.size()-1;

        while(start<end)
        {
            area=min(heights[start],heights[end])*(end-start);
            ans=max(ans,area);

            if(heights[end]<=heights[start]) end--;

            else if(heights[end]>heights[start]) start++;

        }

            return ans;
       

    }
};
