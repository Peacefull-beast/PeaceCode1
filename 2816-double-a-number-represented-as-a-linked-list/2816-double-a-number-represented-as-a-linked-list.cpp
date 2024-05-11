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
    string mult (string str)
    {
        string ans = "";
        int carry = 0;
        for(int  i = str.length()-1; i>=0; i--)
        {
            int num = int(str[i])-48;
            int nnum = num*2 + carry;
            if(nnum <= 9)
            {
                ans = to_string(nnum) + ans; 
                carry = 0;
            }
            else
            {
                ans = to_string(nnum%10) + ans;
                carry = 1;
            }            
        }
        if(carry == 1)
            ans = "1" + ans;
        return ans;
    }
    ListNode* doubleIt(ListNode* head) 
    {
        string str = "";
        while(head!=NULL)
        {
            str = str + to_string(head->val);
            head = head->next;
        }
        
        string str1 = mult(str);
        cout<<str<<endl<<str1;
        ListNode* head1 = new ListNode(int(str1[0])-48);
        ListNode* head2 = head1;
        
        
        for(int i = 1; i < str1.length(); i++)
        {
            ListNode* head = new ListNode(int(str1[i])-48);
            head1->next = head;
            head1= head1->next;
        }
        
        return head2;
    }
};