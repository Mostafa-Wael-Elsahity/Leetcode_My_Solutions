class Solution {
public:
    long long getSum(int num){
        return 1ll*num*(num+1)/2;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(getSum(maxChoosableInteger)<desiredTotal) return false;
        vector<int>memo(1<<maxChoosableInteger,-1);
        function<bool(int,int)> solve=[&](int mask,int score)->bool{
            if(~memo[mask]) return memo[mask];
            for(int i=0;i<maxChoosableInteger;i++){
                int cmask=1<<i;
                if(!(mask&cmask)){
                    if(score+i+1>=desiredTotal || !solve(cmask|mask,score+i+1)){
                        return memo[mask]=1;
                    }
                }
            }
            return memo[mask]=0;
        };
        return solve(0,0);
    }
};