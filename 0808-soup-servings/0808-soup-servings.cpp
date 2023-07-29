class Solution {
public:
    double soupServings(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        double memo[200][200]={};
        function<double(int, int)> calculateDP = [&](int i, int j) -> double {
            if (i <= 0 && j <= 0)  return 0.5;
            if (i <= 0)  return 1;
            if (j <= 0)  return 0;
            if (memo[i][j])  return memo[i][j];
            return memo[i][j] = (calculateDP(i - 4, j) + calculateDP(i - 3, j - 1) +
                               calculateDP(i - 2, j - 2) + calculateDP(i - 1, j - 3))*0.25;
        };
        return n > 4800 ?  1.0 : calculateDP((n + 24) / 25, (n + 24) / 25);
    }
};