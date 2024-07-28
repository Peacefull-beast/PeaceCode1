#include <stack>
#include <string>

using namespace std;

class BrowserHistory {
public:
    stack<string> b; // Stack for back history
    stack<string> f; // Stack for forward history

    BrowserHistory(string homepage) {
        b.push(homepage);
    }
    
    void visit(string url) {
        // Clear the forward stack as we are visiting a new page
        while (!f.empty()) {
            f.pop();
        }
        // Push the current page to the back stack and move to the new page
        b.push(url);
    }
    
    string back(int steps) {
        // Move up to 'steps' pages back
        while (b.size() > 1 && steps-- > 0) {
            f.push(b.top());
            b.pop();
        }
        return b.top();
    }
    
    string forward(int steps) {
        // Move up to 'steps' pages forward
        while (!f.empty() && steps-- > 0) {
            b.push(f.top());
            f.pop();
        }
        return b.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
