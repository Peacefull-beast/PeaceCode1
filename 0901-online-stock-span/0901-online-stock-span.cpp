class StockSpanner {
public:
    stack<pair<int, int>> st; // {price, span}
    
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        
        
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push the current price and its span onto the stack
        st.push({price, span});
        
        return span;
    }
};