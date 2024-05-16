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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(head == NULL || head->next == NULL)
            return NULL;
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            len+=1;
            temp=temp->next;
        }
        
        int del_after = len - n;
        
        if(del_after == 0)
            return head->next;
        //cout<< len <<"  " <<del_after<<endl;
        int i = 1;
        
        temp = head;
        while(i < del_after)
        {
            temp = temp->next;
            i++;
        }
        //cout<< temp->val<< endl;
        temp->next = temp->next->next;
        
        return head;
        
    }
};