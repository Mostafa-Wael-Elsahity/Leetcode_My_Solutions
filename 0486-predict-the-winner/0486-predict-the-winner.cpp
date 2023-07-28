class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size(),sum=0,memo[n+5][n+5];
        memset(memo,-1,sizeof memo);
        for(auto &num:nums) sum+=num;
        function<int(int,int)> solve=[&](int i,int j)->int{
            if(i>j) return 0;
            int &res=memo[i][j];
            if(~res) return res;
            if((i+j)%2!=n%2) res=max(nums[i]+solve(i+1,j),nums[j]+solve(i,j-1));
            else res=min(solve(i+1,j),solve(i,j-1));
            return res;
        };
        return solve(0,n-1)*2>=sum;
    }
};