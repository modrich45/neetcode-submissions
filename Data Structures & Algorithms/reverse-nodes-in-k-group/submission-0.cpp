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

    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=curr->next;
        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            
            if(next==NULL){
                break;
            }
            curr=next;
            next=curr->next;

        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans=new ListNode();
        ListNode* res=ans;
        ListNode* start=head;
        int cnt=0;
        while(head!=NULL){
            cnt++;
            if(cnt==k){
                ListNode* temp=head->next;
                head->next=NULL;
                ans->next=reverse(start);
                while(ans->next!=NULL){
                    ans=ans->next;
                }
                head=temp;
                start=head;
                cnt=0;
            }else{
                head=head->next;
            }
        }
        ans->next=start;
        return res->next;
    }
};
