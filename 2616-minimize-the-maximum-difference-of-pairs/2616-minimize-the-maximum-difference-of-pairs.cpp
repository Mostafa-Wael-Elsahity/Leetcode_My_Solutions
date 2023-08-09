class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size(),l=0,r=1e9,mid,ans=0;
        sort(nums.begin(),nums.end());
        while(l<=r){
            mid=(l+r)/2;
            int ctr=0;
            for(int i=1;i<n;i++){
                if(nums[i]-nums[i-1]<=mid) i++,ctr++;
            }
            if(ctr<p) l=mid+1;
            else r=mid-1,ans=mid;
        }
        return ans;
    }
};