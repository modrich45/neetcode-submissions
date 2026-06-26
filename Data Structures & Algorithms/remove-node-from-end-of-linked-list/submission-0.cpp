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
    int length(ListNode* head){
        int ans=0;
        while(head!=NULL){
            ans++;
            head=head->next;
        }
        return ans;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int len=length(temp);
        int idx=len-n;
        if(idx==0){
            return head->next;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(idx--){
            prev=curr;
            curr=curr->next;
        }
        if(prev==NULL){
            return curr;
        }else{
            prev->next=curr->next;
        }
        return head;
    }
};
