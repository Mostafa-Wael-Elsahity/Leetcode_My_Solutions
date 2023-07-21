class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1));
        
        for(int i=n-1; i>=0; i--) {
            for(int t=0; t<2 * k; t++) {
                if(t % 2 == 0) {
                    dp[i][t] = max(-p[i] + dp[i + 1][t + 1], 0 + dp[i + 1][t]);
                }
                else dp[i][t] = max(p[i] + dp[i + 1][t + 1], 0 + dp[i + 1][t]);
            }
        }
        return dp[0][0];
    }
};