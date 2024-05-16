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
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode* dumNode = new ListNode(0);
        dumNode->next = head;
        
        unordered_map<int, ListNode*> mp;
        mp[0] = dumNode;
        
        int preSum = 0;
        
        while(head != NULL)
        {
            preSum += head->val;
            if(mp.find(preSum) != mp.end())
            {
                ListNode* start = mp[preSum];
                int pf = preSum;
                ListNode* temp = start;
                while(temp->next != head)
                {
                    temp = temp->next;
                    pf += temp->val;
                    mp.erase(pf);
                }
                start->next = head->next;
                
            }
            else
                mp[preSum] = head;
            head = head->next;
        }
        return dumNode->next;
        
    }
};