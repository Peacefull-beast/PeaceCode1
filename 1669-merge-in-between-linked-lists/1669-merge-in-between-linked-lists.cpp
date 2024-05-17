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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        int ind = 1;
        ListNode* temp1 = list1;
        ListNode* temp2 = list1;
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        while (list1 != NULL)
        {
            if(ind == a)
                temp1 = list1;
            if(ind == b+1)
                temp2 = list1;
            list1 = list1->next;
            ind++;
        }
        
        while(list2->next != NULL)
            list2 = list2->next;
        
        temp1->next = head2;
        list2->next = temp2->next;
        
        return head1;
        
    }
};