/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) 
    {
        stack<int>st;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL)
        {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        int ans = 0;
        while(slow != NULL)
        {
            int a = slow->val;
            int b = st.top();

            ans = max(ans, (a+b));

            slow = slow->next;
            st.pop();
        }

        return ans;

    }
};