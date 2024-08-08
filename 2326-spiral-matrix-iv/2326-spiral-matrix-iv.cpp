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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) 
    {
        vector<vector<int>>matrix(n, vector<int>(m, -1));
        
        int top = 0;
        int right = m - 1;
        int left = 0;
        int down = n - 1;
        
        
        
        while(head != NULL)
        {
            for(int i = left; i <= right && head != NULL; i++)
            {
                matrix[top][i] = head->val;
                head = head->next;
            }
            
            top++;
            
            for(int j = top; j <= down && head != NULL; j++)
            {
                matrix[j][right] = head->val;
               head = head->next;
            }
            
            right--;
            
            for(int i = right; i >= left && head != NULL; i--)
            {
                matrix[down][i] = head->val;
                head = head->next;
            }
            
            down--;
            
            for(int j = down; j >= top && head != NULL; j--)
            {
                matrix[j][left] = head->val;
                head = head->next;
            }
            
            left++;
        }
        return matrix;
    }
};