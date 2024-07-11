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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* h1 = new ListNode(0);
        ListNode* h = h1;
        head = head->next;
        int sum = 0;
        while(head != NULL)
        {
            if(head->val == 0)
            {
                ListNode* temp = new ListNode(sum);
                h1->next = temp;
                h1 = h1->next;
                sum = 0;
            }
            
            sum += head->val;
            head = head->next;
        }
        
        return h->next;
    }
};