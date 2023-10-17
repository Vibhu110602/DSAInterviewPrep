
class Solution {
public:
    int len(ListNode *head){
        int cnt=0;
        while(head){
            head=head->next;
            cnt++;
        }
    return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
        ListNode *dummy=new ListNode();
        dummy->next=head;
        ListNode* slow=dummy,*fast=dummy;
        int i=0;
        k=k%len(head);
        while(i++ < k){
            fast=fast->next;
        }
        while(fast && fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=head;
        ListNode *newHead=slow->next;
        slow->next=NULL;
        return newHead;
    }
};