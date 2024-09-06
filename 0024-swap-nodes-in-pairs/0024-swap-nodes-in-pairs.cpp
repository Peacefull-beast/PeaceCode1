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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL)
        return NULL;
        else if(head->next == NULL)
        return head;
        ListNode* temp = head;
        while(head != NULL && head->next != NULL)
        {
            swap(head->val, head->next->val);
            head = head->next->next;
        }
        return temp;
    }
};