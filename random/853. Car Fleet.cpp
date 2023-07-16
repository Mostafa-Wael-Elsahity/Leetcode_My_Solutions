class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<vector<int>>v(n);
        for(int i=0;i<n;++i) v[i]={position[i],speed[i]};
        sort(v.begin(),v.end());
        stack<vector<int>>st;
        for(int i=0;i<n;++i){
            while(!st.empty()&&1LL*(target-v[i][0])*st.top()[1]>=1LL*(target-st.top()[0])*v[i][1]) st.pop();
            st.push(v[i]);
        }
        return st.size();
    }
};
