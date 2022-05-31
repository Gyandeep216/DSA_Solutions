//https://leetcode.com/problems/online-stock-span/

// Efficient Approach using stack

class StockSpanner {
public:
    stack<pair<int,int>> st;
    int days = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 0;
        while(!st.empty() && st.top().first<=price) st.pop();
        if(!st.empty() && st.top().first>price) ans = days - (st.top().second);
        else if(st.empty()) ans = days+1;
        
        st.push({price,days++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */