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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res= new ListNode();
        ListNode* ans=res;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        int carry=0;
        while(ptr1!=NULL && ptr2!=NULL){
            int temp=ptr1->val+ptr2->val+carry;
            if(temp>=10){
                int o=temp%10;
                int t=temp/10;
                carry=t;
                ListNode* temp= new ListNode(o);
                res->next=temp;
                res=res->next;
            }else{
                int o=temp;
                ListNode* temp= new ListNode(o);
                res->next=temp;
                res=res->next;
                carry=0;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1!=NULL){
            int temp=ptr1->val+carry;
            if(temp>=10){
                int o=temp%10;
                int t=temp/10;
                carry=t;
                ListNode* temp= new ListNode(o);
                res->next=temp;
                res=res->next;
            }else{
                int o=temp;
                ListNode* temp= new ListNode(o);
                res->next=temp;
                res=res->next;
                carry=0;
            }
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL){
            int temp=ptr2->val+carry;
            if(temp>=10){
                int o=temp%10;
                int t=temp/10;
                carry=t;
                ListNode* temp= new ListNode(o);
                res->next=temp;
                res=res->next;
            }else{
                int o=temp;
                ListNode* temp= new ListNode(o);
                res->next=temp;
                res=res->next;
                carry=0;
            }
            ptr2=ptr2->next;
        }
        if(carry!=0){
            ListNode* temp=new ListNode(carry);
            res->next=temp;
        }
        return ans->next;
    }
};
