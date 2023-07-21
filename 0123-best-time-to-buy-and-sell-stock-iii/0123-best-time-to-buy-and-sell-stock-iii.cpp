class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size(),k=2;
        vector<int> dp(2 * k + 1), temp(2 * k + 1);
        
        for(int i=n-1; i>=0; i--) {
            for(int t=0; t<2 * k; t++) {
                if(t % 2 == 0) {
                    temp[t] = max(-p[i] + dp[t + 1], 0 + dp[t]);
                }
                else temp[t] = max(p[i] + dp[t + 1], 0 + dp[t]);
            }
            dp = temp;
        }
        return dp[0];
    }
};