class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size(),sum=0,memo[n+5][n+5];
        memset(memo,-1,sizeof memo);
        for(auto &num:nums) sum+=num;
        function<int(int,int)> solve=[&](int i,int j)->int{
            if(i==j) return nums[i];
            int &res=memo[i][j];
            if(~res) return res;
            return res=max(nums[i]-solve(i+1,j),nums[j]-solve(i,j-1));
        };
        return solve(0,n-1)>=0;
    }
};