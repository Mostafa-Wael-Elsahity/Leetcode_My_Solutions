class Solution {
public:
    vector<int>p;
    vector<vector<int>>ans;
    bitset<6>vis;
    int n;
    void calc(int i,vector<int>&nums){
        if(i==n) {
            ans.push_back(p);
            return;
        }
        for(int k=0;k<n;k++)
            if(!vis[k]){
                vis[k]=1;
                p.push_back(nums[k]);
                calc(i+1,nums);
                vis[k]=0;
                p.pop_back();
            }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vis=0;
        calc(0,nums);
        return ans;
    }
};