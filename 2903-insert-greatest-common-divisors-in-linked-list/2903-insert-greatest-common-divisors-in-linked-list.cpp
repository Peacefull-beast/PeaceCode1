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
    int gcd(int a, int b) {
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* head1 = head;
        while(head->next != NULL)
        {
            int ans = gcd(head->val, head->next->val);
            ListNode* temp = new ListNode(ans);
            
            temp->next = head->next;
            head->next = temp;
            head = temp->next;
        }
        
        return head1;
    }
};