class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for(auto asteroid:asteroids){
            if(asteroid<0){
                while(!ans.empty()&&abs(asteroid)>ans.back()&&ans.back()>0)
                    ans.pop_back();
                if(!ans.empty()&&abs(asteroid)==ans.back()) ans.pop_back();
                else if(ans.empty()||ans.back()<0) ans.push_back(asteroid);
            }else{
                ans.push_back(asteroid);
            }
        }
        return ans;
    }
};