class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int n=numbers.size();

        for(int i=0;i<n;i++)
        {
            int rest=target-numbers[i];

            int start=i+1;
            int end=n-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;

                if(numbers[mid]==rest)
                {
                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    return ans;
                }

                else if(numbers[mid]>rest)
                {
                    end=mid-1;
                }

                else 
                start=mid+1;
            }
        }
    }
};
