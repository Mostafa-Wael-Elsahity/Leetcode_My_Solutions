class Solution {
public:
    long long getSum(int num){
        return 1ll*num*(num+1)/2;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(getSum(maxChoosableInteger)<desiredTotal) return false;
        vector<int>dp(1<<maxChoosableInteger,-1);
        function<bool(int,int)> game=[&](int mask,int score)->bool{
            if(dp[mask]!=-1) return dp[mask];
            for(int i=0;i<maxChoosableInteger;i++)
            {
                int cmask = 1<<i;
                if( (mask&cmask) == 0 )
                        if(score+i+1 >= desiredTotal or game((mask|cmask),score+i+1)==false ) return dp[mask]=1;
            }
            return dp[mask]=0;
        };
        return game(0,0);
    }
};