class FreqStack {
public:
    int maxi;
    unordered_map<int, int>freq;
    unordered_map<int, stack<int>>levels;
    FreqStack() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        maxi = 0;
    }
    
    void push(int val) {
        freq[val]++; 
        maxi = max(maxi, freq[val]);
        levels[freq[val]].push(val);
    }
    
    int pop() {
        int top = levels[maxi].top();
        levels[maxi].pop();
        if(levels[freq[top]--].empty()) maxi--; 
        return top;
    }
};
