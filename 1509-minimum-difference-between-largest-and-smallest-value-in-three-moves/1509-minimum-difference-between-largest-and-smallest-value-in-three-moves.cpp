class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=2e9,n=nums.size();
        for(int i=0,j=4;i<4;i++,j--) 
            if(i>n-j||i==n) ans=0;
            else ans=min(ans,nums[n-j]-nums[i]);
        return ans;
    }
};