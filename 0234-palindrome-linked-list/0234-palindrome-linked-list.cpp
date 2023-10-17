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
    ListNode *reverse(ListNode* head){
        if(!head)return head;
        ListNode *prev=NULL,*curr=head,*forw=NULL;
        while(curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return true;
        ListNode *fast=head,*slow=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(head && slow){
            if(head->val!=slow->val)return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};