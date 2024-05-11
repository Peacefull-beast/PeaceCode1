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
    ListNode* removeNodes(ListNode* h) 
    {
        vector<int>list;
        while(h!=NULL)
        {
            list.push_back(h->val);
            h = h->next;
        }
        int  n = list.size();
        ListNode *head = new ListNode(list[n-1]);
        int max = list[n-1];
        for(int j = n-2; j>=0; j--)
        {
            if(list[j] >= max)
            {
                ListNode *temp = new ListNode(list[j]);
                temp->next = head;
                head = temp;
                max = list[j];
            }
        }
        return head;
            
    }
};