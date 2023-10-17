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
    int length(ListNode *head){
        int len=0;
        while(head){
            head=head->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head ||length(head)<k)return head;
        ListNode* prev=NULL,*forw=NULL,*curr=head;
        int cnt=0;
        while(curr && cnt<k){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
            cnt++;
        }
        if(forw)head->next=reverseKGroup(forw,k);
        return prev;
    }
};