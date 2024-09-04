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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>&data, int low, int high)
    {
        if(low > high)
        return NULL;

        if(low == high)
        {
            TreeNode* root = new TreeNode(data[low]);
            return root;
        }
        int mid = low + (high-low)/2;
        TreeNode* root = new TreeNode(data[mid]);

        TreeNode* left = solve(data, low, mid-1);
        TreeNode* right = solve(data, mid+1, high);

        root->left = left;
        root->right = right;

        return root;

        
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == NULL)
        return NULL;
        vector<int>data;
        while(head != NULL)
        {
            data.push_back(head->val);
            head = head->next;
        }

        int low = 0;
        int high = data.size()-1;

        TreeNode* ans = solve(data, low, high);
        return ans;
    }
};